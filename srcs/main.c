/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:34 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/06 17:16:45 by hyunjuki         ###   ########.fr       */
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

int	init_env_arr(t_vararr *env, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (append_element(env, envp[i]) == -1)
			return (-1);
		i++;
	}
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

static int	exec_bin(void)
{
	return (0);
}

void	check_leak(void)
{
	system("leaks --list minishell");
}

int	main(int argc, char **argv, char **envp)
{
	int			flag;
	char		*line;
	char		**splited;
	t_vararr	*env;

	atexit(check_leak);
	env = make_new_arr(30);
	if (!env)
		return (-1);
	if (init(env, envp) == -1)
		return (-1);
	line = NULL;
	line = get_line(line);
	while (line != NULL)
	{
		flag = 0;
		splited = ft_split(line, ' ');
		if (split_len(splited) != 0)
		{
			flag += exec_builtins(splited, split_len(splited), env);
			if (flag == 0)
				flag += exec_bin();
			if (flag == 0)
				printf("h2osh: %s: command not found\n", splited[0]);
		}
		splited = freeall(splited);
		line = get_line(line);
	}
	return (0);
}

