/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vararr_oper4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:43:06 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/17 12:12:31 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vararr.h"

static void	prt_precision(char *str, int prec)
{
	int	i;

	i = 0;
	while (i < prec)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}

static void	prt_with_double_quotes(char *key, char *value, int prec)
{
	prt_precision(key, prec);
	ft_putchar_fd('"', 1);
	ft_putstr_fd(value, 1);
	ft_putchar_fd('"', 1);
}

void	print_all_string(char *prefix, char **arr, int value_quote, int no_val)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] != NULL)
	{
		j = -1;
		if (no_val == 1 || ft_strnstr(arr[i], "=", ft_strlen(arr[i])) != NULL)
		{
			if (prefix != NULL)
				ft_putstr_fd(prefix, 1);
			if (ft_strnstr(arr[i], "=", ft_strlen(arr[i])) != NULL)
				j = (ft_strnstr(arr[i], "=", ft_strlen(arr[i])) - arr[i]);
			if (!value_quote)
				ft_putstr_fd(arr[i], 1);
			else if (j >= 0)
				prt_with_double_quotes(arr[i], &arr[i][j + 1], j + 1);
			else
				ft_putstr_fd(arr[i], 1);
			ft_putchar_fd('\n', 1);
		}
		i++;
	}
}
