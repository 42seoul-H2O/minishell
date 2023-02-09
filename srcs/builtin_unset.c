/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:49:21 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/09 18:40:08 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	builtin_unset(t_list *node, t_vararr *env)
{
	int	i;

	i = 0;
	while (i < node->args->len)
	{
		ft_unsetenv(env, get_element(node->args, i));
		i++;
	}
}
