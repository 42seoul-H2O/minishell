/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:40:55 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/17 18:58:35 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execution(t_cmdlist *node, t_vararr *env)
{
	t_cmdlist	*curr;
	pid_t		pid;

	curr = node;
	if (exec_single_builtin(node, env))
		return ;
	while (curr->next != NULL)
	{
		pipe(curr->pipe);
		curr = curr->next;
	}
	curr = node;
	while (curr)
	{
		close_prev_pipe(curr);
		pid = fork();
		if (pid < 0)
			ft_exit(11);
		if (pid == 0)
			exec_child(curr, env);
		curr = curr->next;
	}
	break_pipe_and_wait_child(node);
}

void	break_pipe_and_wait_child(t_cmdlist *node)
{
	int	stat;

	while (node)
	{
		if (node->pipe[0] != 0)
		{
			close(node->pipe[0]);
			node->pipe[0] = 0;
		}
		if (node->pipe[1] != 1)
		{
			close(node->pipe[1]);
			node->pipe[1] = 1;
		}
		node = node->next;
	}
	set_sig_ignore();
	wait(&stat);
	if (WIFSIGNALED(stat))
		write(1, "\n", 1);
	set_sig_handler();
}

void	exec_child(t_cmdlist *node, t_vararr *env)
{
	set_pipe_fd(node);
	set_redirection(node);
	if (node->cmd_type == ERROR)
	{
		ft_putstr_fd("h2osh : ", 2);
		ft_putstr_fd(node->cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	else if (node->cmd_type == EXECUTABLE)
	{
		if (execve(node->cmd, node->args->words, env->arr) < 0)
			ft_exit(11);
	}
	else
		exec_builtins(node, env);
}