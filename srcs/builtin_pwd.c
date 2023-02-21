/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:13:12 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/21 12:14:21 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "minishell.h"

void	builtin_pwd(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	if (buf == NULL)
	{
		perror("h2osh: pwd: ");
		g_exit_code = 1;
	}
	ft_putendl_fd(buf, 1);
	free(buf);
	g_exit_code = 0;
}
