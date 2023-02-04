/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:29:08 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/04 19:28:34 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	is_all_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit((int)s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	builtin_exit(int errnum)
{
	printf("%s\n", "exit");
	exit(errnum);
}

void	check_exit_code(char **input, int len)
{
	if (len == 1)
		builtin_exit(0);
	else if (len == 2)
	{
		if (is_all_digit(input[1]))
			builtin_exit(atoi(input[1]));
		printf("exit\nh2osh: exit: %s: numeric argument required\n",
			input[1]);
		exit(2);
	}
	else
		printf("exit\nh2osh: exit: too many arguments\n");
}
