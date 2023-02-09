/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:29:08 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/09 18:22:41 by hyunjuki         ###   ########.fr       */
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

void	builtin_exit(t_list	*node)
{
	if (node->args->len == 0)
		ft_exit(0);
	else if (node->args->len == 1)
	{
		if (is_all_digit(get_element(node->args, 1)))
			ft_exit(ft_atoi(get_element(node->args, 1)));
		printf("exit\nh2osh: exit: %s: numeric argument required\n",
			get_element(node->args, 1));
		exit(2);
	}
	else
		printf("exit\nh2osh: exit: too many arguments\n");
}

void	ft_exit(int errnum)
{
	printf("%s\n", "exit");
	exit(errnum);
}
