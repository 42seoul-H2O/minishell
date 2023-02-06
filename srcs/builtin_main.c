/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:05:47 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/06 11:12:49 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

extern char	**environ;

static void	dummy(void)
{
}

int	exec_builtins(char **input, int len)
{
	int	cmd_len;

	if (len == 0)
		return (0);
	cmd_len = ft_strlen(input[0]);
	if (cmd_len == 4 && ft_strnstr(input[0], "exit", 4) != NULL)
		check_exit_code(input, len);
	else if (cmd_len == 3 && ft_strnstr(input[0], "pwd", 3) != NULL)
		builtin_pwd();
	else if (cmd_len == 2 && ft_strnstr(input[0], "cd", 2) != NULL)
		builtin_cd(input[1]);
	else if (cmd_len == 6 && ft_strnstr(input[0], "export", 6) != NULL)
		builtin_export(input, environ);
	else if (cmd_len == 5 && ft_strnstr(input[0], "unset", 5) != NULL)
		dummy();
	else if (cmd_len == 4 && ft_strnstr(input[0], "echo", 4) != NULL)
		builtin_echo(input, environ);
	else if (cmd_len == 3 && ft_strnstr(input[0], "env", 3) != NULL)
		builtin_env(input, environ);
	else
	{
		printf("h2osh: %s: command not found\n", input[0]);
		return (0);
	}
	return (1);
}
