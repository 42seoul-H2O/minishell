/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:34 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/13 17:02:50 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init(t_vararr **env, char **envp)
{
	char	*temp;

	set_sig_handler();
	*env = make_new_arr(30);
	if (!env)
		return (-1);
	if (init_env_arr(*env, envp) == -1)
		return (-1);
	temp = ft_getenv(*env, "SHLVL");
	if (!temp)
		temp = ft_strdup("1");
	else
		temp = ft_itoa(ft_atoi(temp) + 1);
	if (!temp)
		return (-1);
	ft_setenv(*env, "SHLVL", temp, 1);
	free(temp);
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

static int	exec_bin(t_cmdlist *node, t_vararr *env)
{
	int		stat;
	pid_t	pid;
	char	*temp;

	if (node->cmd_type == EXECUTABLE)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(node->cmd, node->args->arr, env->arr);
		}
		wait(&stat);
		return (1);
	}
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
	t_cmdlist	*parsed;

	//atexit(check_leak);
	if (init(&env, envp) == -1)
		return (-1);
	line = NULL;
	line = get_line(line);
	parsed = NULL;
	while (line != NULL)
	{
		flag = 0;
		input = parse(line, env);
		if (input->len != 0)
		{
			parsed = list_maker(input, env);
			flag += exec_builtins(parsed, env);
			if (flag == 0)
				flag += exec_bin(parsed, env);
			if (flag == 0)
				printf("h2osh: %s: command not found\n", parsed->cmd);
			destroy_list(parsed);
		}
		destroy_arr(input);
		line = get_line(line);
	}
	return (0);
}
