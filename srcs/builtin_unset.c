/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:49:21 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/11 14:57:19 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	builtin_unset(t_cmdlist *node, t_vararr *env)
{
	int	i;

	i = 1;
	while (i < node->args->len)
	{
		ft_unsetenv(env, get_element(node->args, i));
		i++;
	}
}
