/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:23:42 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/06 17:33:04 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	builtin_env(char **input, t_vararr *env)
{
	if (input[1] == NULL)
		print_all_string(NULL, env->arr, 0, 0);
	else
		printf("h2osh: env: too many argument\n");
}
