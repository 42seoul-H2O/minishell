/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:17:07 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/21 14:58:36 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int	ft_wifsignaled(int stat)
{
	return (((stat & 0177) != 0177) && (stat != 0));
}

static int	ft_isdir(int mode)
{
	return ((mode & 0170000) == 0040000);
}

static int	ft_isreg(int mode)
{
	return ((mode & 0170000) == 0100000);
}

int	ft_access(const char *path)
{
	struct stat	s_stat;

	if (ft_strchr(path, '/') == NULL)
		return (-1);
	if (stat(path, &s_stat))
		return (-1);
	if (ft_isdir(s_stat.st_mode))
		return (-2);
	if (ft_isreg(s_stat.st_mode))
		return (0);
	return (-1);
}

