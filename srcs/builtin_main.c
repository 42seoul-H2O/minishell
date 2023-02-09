/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:05:47 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/09 18:18:09 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	exec_builtins(t_list *exec, t_vararr *env)
{
	if (exec->cmd_type == EXIT)
		check_exit_code(input);
	else if (exec->cmd_type == PWD)
		builtin_pwd();
	else if (exec->cmd_type == CD)
		builtin_cd(input->arr[1]);
	else if (exec->cmd_type == EXPORT)
		builtin_export(input->arr, env);
	else if (exec->cmd_type == UNSET)
		builtin_unset(input->arr, env);
	else if (exec->cmd_type == ECHO)
		builtin_echo(input->arr, env);
	else if (exec->cmd_type == ENV)
		builtin_env(input->arr, env);
	else
		return (0);
	return (1);
}
