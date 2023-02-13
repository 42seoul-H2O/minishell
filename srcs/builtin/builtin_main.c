/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:05:47 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/11 14:57:19 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

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
		builtin_echo(exec, env);
	else if (exec->cmd_type == ENV)
		builtin_env(exec, env);
	else
		return (0);
	return (1);
}
