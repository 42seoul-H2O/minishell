/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:34 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/13 16:38:20 by hyunjuki         ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	int			flag;
	char		*line;
	t_str		parsed;
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
		flag = 0;
		parsed = parse(line, env);
		if (parsed.word_count != 0)
		{
			flag += exec_builtins(parsed.words, parsed.word_count, env);
			if (flag == 0)
				flag += exec_bin();
			if (flag == 0)
				printf("h2osh: %s: command not found\n", parsed.words[0]);
		}
		destroy_t_str(&parsed);
		line = get_line(line);
	}
	return (0);
}
