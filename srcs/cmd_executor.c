/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:40:55 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/14 17:20:05 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execution(t_cmdlist *node, t_vararr *env)
{
	if (node->prev == NULL && node->next == NULL \
		&& node->cmd_type != ERROR && node->cmd_type != EXECUTABLE)
		exec_builtins(node, env);
	else if (node->cmd_type == EXECUTABLE)
		exec_bin(node, env);
	else
		printf("h2osh: %s: command not found\n", node->cmd);
}

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
