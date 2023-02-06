/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:49:21 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/06 19:24:19 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	builtin_unset(char **input, t_vararr *env)
{
	int	i;

	i = 1;
	while (input[i] != NULL)
	{
		ft_unsetenv(env, input[i]);
		i++;
	}
}
