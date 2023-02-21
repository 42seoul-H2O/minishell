/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:17:07 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/21 12:06:54 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_wifsignaled(int stat)
{
	return (((stat & 0177) != 0177) && (stat != 0));
}

int	ft_access(const char *path)
{
	struct stat	s_stat;

	if (stat(path, &s_stat))
		return (-1);
	if (S_ISDIR(s_stat.st_mode))
		return (-2);
	if (S_ISREG(s_stat.st_mode))
		return (0);
	return (-1);
}

