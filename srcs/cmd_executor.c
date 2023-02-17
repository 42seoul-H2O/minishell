/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:40:55 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/17 16:03:35 by hyunjuki         ###   ########.fr       */
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
	while (node)
	{
		if (node->prev && node->prev->prev)
			close_prev_pipe(node);
		pid = fork();
		if (pid == 0)
			exec_child(node, env);
		if (node->next == NULL)
			close_prev_pipe(node);
		node = node->next;
	}
	wait(NULL);
}

void	set_redirection(t_cmdlist *node)
{
}

void	set_pipe_fd(t_cmdlist *node)
{
}

void	close_prev_pipe(t_cmdlist *node)
{
}

void	exec_child(t_cmdlist *node, t_vararr *env)
{
}
/*
int	exec_bin(t_cmdlist *node, t_vararr *env)
{
	int		stat;
	pid_t	pid;
	char	*temp;

	if (node->cmd_type == EXECUTABLE)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(node->cmd, node->args->arr, env->arr);
		}
		set_sig_ignore();
		wait(&stat);
		if (WIFSIGNALED(stat))
			write(1, "\n", 1);
		set_sig_handler();
		return (1);
	}
	return (0);
}
*/
