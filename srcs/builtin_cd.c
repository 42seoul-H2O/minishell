/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:12:53 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/11 15:51:18 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	builtin_cd(t_cmdlist *node)
{
	if (node->args->len == 1)
	{
		printf("h2osh: cd: argument not found\n");
		return ;
	}
	if (node->args->len != 2)
	{
		printf("h2osh: cd: too many arguments\n");
		return ;
	}
	if (access(get_element(node->args, 1), F_OK) == 0)
		if (chdir(get_element(node->args, 1)) == 0)
			return ;
	ft_putstr_fd("h2osh: cd: ", 1);
	ft_putstr_fd(get_element(node->args, 1), 1);
	ft_putstr_fd(": ", 1);
	perror(NULL);
}
