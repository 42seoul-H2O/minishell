/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:23:42 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/11 14:57:19 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	builtin_env(t_cmdlist *node, t_vararr *env)
{
	if (get_element(node->args, 1) == NULL)
		print_all_string(NULL, env->arr, 0, 0);
	else
		printf("h2osh: env: too many argument\n");
}
