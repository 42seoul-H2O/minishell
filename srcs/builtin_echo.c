/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:35:53 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/17 21:11:25 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	check_n_option(char *input)
{
	int	i;

	if (input == NULL)
		return (0);
	if (input[0] != '-')
		return (0);
	i = 1;
	while (input[i] != '\0')
	{
		if (input[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	builtin_echo(t_cmdlist *node)
{
	int		i;
	char	*temp;

	i = 1;
	i += check_n_option(node->args->words[1]);
	while (i < node->args->word_count)
	{
		ft_putstr_fd(node->args->words[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putchar_fd('\b', 1);
	if (check_n_option(get_element(node->args, 1)) != 1)
		ft_putchar_fd('\n', 1);
}
