/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:12:53 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/21 16:05:42 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "minishell.h"

static void	prt_error(t_cmdlist *node)
{
	ft_putstr_fd("h2osh: cd: ", 2);
	ft_putstr_fd(node->args->words[1], 2);
	ft_putstr_fd(": ", 2);
	perror(NULL);
}

static int	check_arg_count(int cnt)
{
	if (cnt == 1)
		ft_putstr_fd("h2osh: cd: argument not found\n", 2);
	else if (cnt != 2)
		ft_putstr_fd("h2osh: cd: too many arguments\n", 2);
	else
		return (0);
	return (1);
}

void	builtin_cd(t_cmdlist *node, t_vararr *env)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	if (!buf)
		exit(11);
	if (check_arg_count(node->args->words_count))
	{
		g_exit_code = 1;
		return ;
	}
	if (access(node->args->words[1], F_OK) == 0)
	{
		if (chdir(node->args->words[1]) == 0)
		{
			ft_setenv(env, "OLDPWD", buf, 1);
			free(buf);
			g_exit_code = 0;
			return ;
		}
	}
	prt_error(node);
	free(buf);
	g_exit_code = 1;
}
