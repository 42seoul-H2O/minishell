/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:05:47 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/17 21:39:27 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "minishell.h"

int	exec_single_builtin(t_cmdlist *exec, t_vararr *env)
{
	int	temp;

	if (exec->next == NULL && exec->prev == NULL \
		&& exec->cmd_type > EXECUTABLE)
	{
		temp = set_redirection(exec);
		if (temp != 0)
		{
			ft_putstr_fd("h2osh : ", 2);
			ft_putstr_fd(exec->args->words[temp + 1], 2);
			ft_putstr_fd(": ", 2);
			perror(NULL);
			//g_error_code = 1;
		}
		exec_builtins(exec, env);
		//g_error_code = 0;
		return (1);
	}
	return (0);
}

int	exec_builtins(t_cmdlist *exec, t_vararr *env)
{
	if (exec->cmd_type == EXIT)
		builtin_exit(exec);
	else if (exec->cmd_type == PWD)
		builtin_pwd();
	else if (exec->cmd_type == CD)
		builtin_cd(exec);
	else if (exec->cmd_type == EXPORT)
		builtin_export(exec, env);
	else if (exec->cmd_type == UNSET)
		builtin_unset(exec, env);
	else if (exec->cmd_type == ECHO)
		builtin_echo(exec);
	else if (exec->cmd_type == ENV)
		builtin_env(exec, env);
	else
		return (0);
	return (1);
}
