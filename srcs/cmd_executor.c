/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:40:55 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/17 14:53:56 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execution(t_cmdlist *node, t_vararr *env)
{
	t_cmdlist	*curr;

	curr = node;
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
