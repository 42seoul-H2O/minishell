/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:29:08 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/04 14:49:38 by hyunjuki         ###   ########.fr       */
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
	if (ft_strnstr(line, "exit", 4) != NULL)
	{
		builtin_exit(0);
	}
	if (ft_strnstr(line, "exit", 4) != NULL)
		builtin_exit(ft_atoi(line + 4));
	printf("%s\n", line);
}
