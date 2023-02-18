/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:23:42 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/18 15:12:39 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "minishell.h"

void	builtin_env(t_cmdlist *node, t_vararr *env)
{
	if (node->args->word_count == 1)
	{
		print_all_string(NULL, env->arr, 0, 0);
		g_exit_code = 0;
	}
	else
	{
		ft_putstr_fd("h2osh: env: too many argument\n", 2);
		g_exit_code = 1;
	}
}
