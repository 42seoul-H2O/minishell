/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:05:47 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/04 18:28:49 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

extern char	**environ;

static void	dummy(void)
{
}

void	exec_builtins(char **input, int len)
{
	if (ft_strnstr(input[0], "exit", 4) != NULL)
		check_exit_code(input, len);
	else if (ft_strnstr(input[0], "pwd", 3) != NULL)
		builtin_pwd();
	else if (ft_strnstr(input[0], "cd", 3) != NULL)
		builtin_cd(input[1]);
	else if (ft_strnstr(input[0], "export", 6) != NULL)
		builtin_export(input, environ);
	else if (ft_strnstr(input[0], "unset", 5) != NULL)
		dummy();
	else if (ft_strnstr(input[0], "echo", 3) != NULL)
		dummy();
	else if (ft_strnstr(input[0], "env", 3) != NULL)
		builtin_env(input, environ);
	else
		printf("h2osh: %s: command not found\n", input[0]);
}
