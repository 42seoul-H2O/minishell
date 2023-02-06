/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:05:47 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/06 15:32:13 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	dummy(void)
{
}

int	exec_builtins(char **input, int len, t_vararr *env)
{
	int	cmd_len;

	if (len == 0)
		return (0);
	cmd_len = ft_strlen(input[0]);
	if (cmd_len == 4 && ft_strncmp(input[0], "exit", 4) == 0)
		check_exit_code(input, len);
	else if (cmd_len == 3 && ft_strncmp(input[0], "pwd", 3) == 0)
		builtin_pwd();
	else if (cmd_len == 2 && ft_strncmp(input[0], "cd", 2) == 0)
		builtin_cd(input[1]);
	else if (cmd_len == 6 && ft_strncmp(input[0], "export", 6) == 0)
		builtin_export(input, env);
	else if (cmd_len == 5 && ft_strncmp(input[0], "unset", 5) == 0)
		builtin_unset(input, env);
	else if (cmd_len == 4 && ft_strncmp(input[0], "echo", 4) == 0)
		builtin_echo(input, env);
	else if (cmd_len == 3 && ft_strncmp(input[0], "env", 3) == 0)
		builtin_env(input, env);
	else
	{
		printf("h2osh: %s: command not found\n", input[0]);
		return (0);
	}
	return (1);
}
