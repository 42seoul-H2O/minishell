/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:34 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/06 14:47:57 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init(t_vararr *env, char **envp)
{
	set_sig_handler();
	if (init_env_arr(env, envp) == -1)
		return (-1);
	return (0);
}

static char	**freeall(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static int	split_len(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	char		**splited;
	t_vararr	*env;

	env = make_new_arr(30);
	if (!env)
		return (-1);
	if (init(env, envp) == -1)
		return (-1);
	line = NULL;
	line = get_line(line);
	while (line != NULL)
	{
		splited = ft_split(line, ' ');
		exec_builtins(splited, split_len(splited), env);
		splited = freeall(splited);
		line = get_line(line);
	}
	return (0);
}

