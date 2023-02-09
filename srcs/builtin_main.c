/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:05:47 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/09 15:20:31 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	exec_builtins(t_vararr *input, t_vararr *env)
{
	int	cmd_len;

	if (input->len == 0)
		return (0);
	cmd_len = ft_strlen(input->arr[0]);
	if (cmd_len == 4 && ft_strncmp(input->arr[0], "exit", 4) == 0)
		check_exit_code(input);
	else if (cmd_len == 3 && ft_strncmp(input->arr[0], "pwd", 3) == 0)
		builtin_pwd();
	else if (cmd_len == 2 && ft_strncmp(input->arr[0], "cd", 2) == 0)
		builtin_cd(input->arr[1]);
	else if (cmd_len == 6 && ft_strncmp(input->arr[0], "export", 6) == 0)
		builtin_export(input->arr, env);
	else if (cmd_len == 5 && ft_strncmp(input->arr[0], "unset", 5) == 0)
		builtin_unset(input->arr, env);
	else if (cmd_len == 4 && ft_strncmp(input->arr[0], "echo", 4) == 0)
		builtin_echo(input->arr, env);
	else if (cmd_len == 3 && ft_strncmp(input->arr[0], "env", 3) == 0)
		builtin_env(input->arr, env);
	else
		return (0);
	return (1);
}
