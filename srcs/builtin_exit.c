/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:29:08 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/17 11:17:14 by hyunjuki         ###   ########.fr       */
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

void	builtin_exit(t_cmdlist *node)
{
	if (node->args->len == 1)
		ft_exit(0);
	else if (node->args->len == 2)
	{
		if (is_all_digit(get_element(node->args, 1)))
			ft_exit(ft_atoi(get_element(node->args, 1)));
		ft_putstr_fd("exit\nh2osh: exit: ", 2);
		ft_putstr_fd(get_element(node->args, 1), 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(2);
	}
	else
		ft_putstr_fd("exit\nh2osh: exit: too many arguments\n", 2);
}

void	ft_exit(int errnum)
{
	ft_putendl_fd("exit", 2);
	exit(errnum);
}
