/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:29:08 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/04 15:26:11 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	builtin_exit(int errnum)
{
	printf("%s\n", "exit");
	exit(errnum);
}

void	exec_builtins(char *line)
{
	int	line_len;

	line_len = ft_strlen(line);
	if (line_len > 5 && ft_strnstr(line, "exit", 4) != NULL
		&& ft_isdigit(line[5]))
		builtin_exit(ft_atoi(line + 4));
	else if (ft_strnstr(line, "exit", 4) != NULL)
		builtin_exit(0);
	else if (ft_strnstr(line, "pwd", 3) != NULL)
		builtin_pwd();
	else
		printf("h2osh: %s: command not found\n", line);
}
