/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:34 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/09 15:25:11 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init(t_vararr **env, char **envp)
{
	set_sig_handler();
	*env = make_new_arr(30);
	if (!env)
		return (-1);
	if (init_env_arr(*env, envp) == -1)
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

static t_vararr	*parse_input(char *s, char c)
{
	char		**splited;
	t_vararr	*result;
	int			i;

	i = 0;
	result = make_new_arr(10);
	if (!result)
		return (NULL);
	splited = ft_split(s, c);
	while (splited[i] != NULL)
	{
		append_element(result, splited[i]);
		i++;
	}
	free_arr(splited);
	return (result);
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

static void	check_leak(void)
{
	system("leaks --list minishell | grep leaks");
}

int	main(int argc, char **argv, char **envp)
{
	int			flag;
	char		*line;
	t_vararr	*input;
	t_vararr	*env;

	atexit(check_leak);
	if (init(&env, envp) == -1)
		return (-1);
	line = NULL;
	line = get_line(line);
	while (line != NULL)
	{
		flag = 0;
		input = parse_input(line, ' ');
		if (input->len != 0)
		{
			flag += exec_builtins(input, env);
			if (flag == 0)
				flag += exec_bin();
			if (flag == 0)
				printf("h2osh: %s: command not found\n", input->arr[0]);
		}
		destroy_arr(input);
		line = get_line(line);
	}
	return (0);
}
