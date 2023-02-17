/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:12:53 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/17 21:09:38 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	builtin_cd(t_cmdlist *node)
{
	if (node->args->word_count == 1)
	{
		ft_putstr_fd("h2osh: cd: argument not found\n", 2);
		return ;
	}
	if (node->args->word_count != 2)
	{
		ft_putstr_fd("h2osh: cd: too many arguments\n", 2);
		return ;
	}
	if (access(node->args->words[1], F_OK) == 0)
		if (chdir(node->args->words[1]) == 0)
			return ;
	ft_putstr_fd("h2osh: cd: ", 2);
	ft_putstr_fd(node->args->words[1], 2);
	ft_putstr_fd(": ", 1);
	perror(NULL);
}
