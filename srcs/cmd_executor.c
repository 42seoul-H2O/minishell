/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:40:55 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/19 16:07:48 by hyunjuki         ###   ########.fr       */
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
	check_heredoc(node);
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
	break_pipe_and_wait_child(node, pid);
}

void	break_pipe_and_wait_child(t_cmdlist *node, pid_t last_child)
{
	int	stat;
	int	processes;

	processes = 0;
	while (node)
	{
		if (node->pipe[0] != 0)
			close(node->pipe[0]);
		if (node->pipe[1] != 1)
			close(node->pipe[1]);
		node = node->next;
		processes++;
	}
	set_sig_ignore();
	while (processes--)
		wait(&stat);
	if (WIFSIGNALED(stat))
	{
		stat += 128;
		write(1, "\n", 1);
	}
	set_sig_handler();
	g_exit_code = (stat % 255);
	//destroy_heredoc();
}

void	exec_child(t_cmdlist *node, t_vararr *env)
{
	int	temp;

	set_pipe_fd(node);
	temp = set_redirection(node);
	if (temp != 0)
		puterr_prompt_and_exit(node->args->words[temp], strerror(errno), 1);
	if (node->cmd_type == NO_CMD)
		exit(0);
	if (node->cmd_type == ERROR)
		puterr_prompt_and_exit(node->cmd, "command not found", 127);
	else if (node->cmd_type == EXECUTABLE)
		if (execve(node->cmd, node->args->words, env->arr) < 0)
			puterr_prompt_and_exit(node->cmd, strerror(errno), 126);
	close(0);
	exec_builtins(node, env);
	exit(g_exit_code);
}

void	puterr_prompt_and_exit(char *target, char *err, int code)
{
	ft_putstr_fd("h2osh : ", 2);
	ft_putstr_fd(target, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err, 2);
	exit(code);
}
