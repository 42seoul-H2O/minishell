/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:29:08 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/18 15:13:28 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "minishell.h"

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
	if (node->args->word_count == 1 && \
		node->next == NULL && node->prev == NULL)
		ft_exit(0);
	else if (node->args->word_count == 1)
		exit(0);
	else if (node->args->word_count == 2)
	{
		if (is_all_digit(node->args->words[1]))
			ft_exit(ft_atoi(node->args->words[1]));
		ft_putstr_fd("exit\nh2osh: exit: ", 2);
		ft_putstr_fd(node->args->words[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(2);
	}
	else
	{
		ft_putstr_fd("exit\nh2osh: exit: too many arguments\n", 2);
		g_exit_code = 1;
	}
}

void	ft_exit(int errnum)
{
	ft_putendl_fd("exit", 2);
	exit(errnum);
}
