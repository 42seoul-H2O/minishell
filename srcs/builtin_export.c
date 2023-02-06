/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:41:07 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/06 16:09:04 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"



void	builtin_export(char **input, t_vararr *env)
{
	int	i;

	if (input[1] == NULL)
	{
		i = 0;
		while ((env->arr)[i] != NULL)
			printf("declare -x %s\n", (env->arr)[i++]);
	}
}
