/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:12:53 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/04 17:19:27 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	builtin_cd(char *path)
{
	if (path == NULL)
	{
		printf("h2osh: cd: argument not found\n");
		return ;
	}
	if (access(path, F_OK) == 0)
		if (chdir(path) == 0)
			return ;
	ft_putstr_fd("h2osh: cd: ", 1);
	ft_putstr_fd(path, 1);
	ft_putstr_fd(": ", 1);
	perror(NULL);
}
