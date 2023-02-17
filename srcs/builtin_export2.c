/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:34:19 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/17 11:20:35 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	swap_element(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	builtin_export_check_args(char *argument, t_vararr *env)
{
	char	*temp;

	if (!ft_isalpha(argument[0]))
	{
		ft_putstr_fd("h2osh: export: '", 2);
		ft_putstr_fd(argument, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
	else if (ft_strchr(argument, '=') == NULL)
		append_element(env, argument);
	else
	{
		temp = ft_substr(argument, 0, ft_strchr(argument, '=') - argument);
		ft_setenv(env, temp,
			&argument[ft_strchr(argument, '=') - argument + 1], 1);
		free(temp);
	}
}
