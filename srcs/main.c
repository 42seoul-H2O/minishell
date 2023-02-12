/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:34 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/11 21:33:23 by hyunjuki         ###   ########.fr       */
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

static int	is_builtin(t_cmdlist *node)
{
	if (ft_strncmp(node->cmd, "echo", ft_strlen(node->cmd)) == 0)
		node->cmd_type = ECHO;
	else if (ft_strncmp(node->cmd, "env", ft_strlen(node->cmd)) == 0)
		node->cmd_type = ENV;
	else if (ft_strncmp(node->cmd, "export", ft_strlen(node->cmd)) == 0)
		node->cmd_type = EXPORT;
	else if (ft_strncmp(node->cmd, "exit", ft_strlen(node->cmd)) == 0)
		node->cmd_type = EXIT;
	else if (ft_strncmp(node->cmd, "pwd", ft_strlen(node->cmd)) == 0)
		node->cmd_type = PWD;
	else if (ft_strncmp(node->cmd, "unset", ft_strlen(node->cmd)) == 0)
		node->cmd_type = UNSET;
	else if (ft_strncmp(node->cmd, "cd", ft_strlen(node->cmd)) == 0)
		node->cmd_type = CD;
	else
		return (0);
	return (1);
}

static char	*is_executable(t_cmdlist *node, t_vararr *env)
{
	char	**path;
	char	*temp;
	char	*check_path;
	int		i;

	temp = NULL;
	if (ft_getenv(env, "PATH") != NULL)
		temp = ft_strdup(ft_getenv(env, "PATH"));
	path = ft_split(temp, ':');
	if (temp)
		free(temp);
	i = 0;
	while (path[i] != NULL)
	{
		check_path = ft_strjoin(path[i], "/");
		temp = ft_strjoin(check_path, node->cmd);
		free(check_path);
		if (access(temp, F_OK) == 0)
		{
			free_arr(path);
			return (temp);
		}
		i++;
		free(temp);
		temp = NULL;
	}
	free_arr(path);
	if (access(node->cmd, F_OK) == 0)
		return (ft_strdup(node->cmd));
	return (NULL);
}

static void	check_cmd_type(t_cmdlist *node, t_vararr *env)
{
	char	*temp;

	if (is_builtin(node) == 1)
		return ;
	temp = is_executable(node, env);
	if (temp != NULL)
	{
		free(node->cmd);
		node->cmd = temp;
		node->cmd_type = EXECUTABLE;
		return ;
	}
	node->cmd_type = ERROR;
}

static void	copy_vararr(t_vararr *dst, t_vararr *src)
{
	int	i;

	i = 0;
	while (i < src->len)
	{
		append_element(dst, get_element(src, i));
		i++;
	}
}

static t_cmdlist	*list_maker(t_vararr *input, t_vararr *env)
{
	t_cmdlist	*result;

	result = make_new_node(NULL);
	copy_vararr(result->args, input);
	set_cmd(result, get_element(result->args, 0));
	check_cmd_type(result, env);
	return (result);
}

int	main(int argc, char **argv, char **envp)
{
	int			flag;
	char		*line;
	t_vararr	*input;
	t_vararr	*env;
	t_cmdlist	*parsed;

	atexit(check_leak);
	if (init(&env, envp) == -1)
		return (-1);
	line = NULL;
	line = get_line(line);
	parsed = NULL;
	while (line != NULL)
	{
		flag = 0;
		input = parse_input(line, ' ');
		if (input->len != 0)
		{
			parsed = list_maker(input, env);
			flag += exec_builtins(parsed, env);
			if (flag == 0)
				flag += exec_bin(parsed, env);
			if (flag == 0)
				printf("h2osh: %s: command not found\n", parsed->cmd);
			destory_list(parsed);
		}
		destroy_arr(input);
		line = get_line(line);
	}
	return (0);
}
