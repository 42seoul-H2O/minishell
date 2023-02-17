/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:13:12 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/17 22:31:22 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	builtin_pwd(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	if (buf == NULL)
	{
		perror("pwd : failed to getcwd()\n");
		exit(1);
	}
	ft_putendl_fd(buf, 1);
	free(buf);
}
