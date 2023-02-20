/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:57:37 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/20 18:03:13 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_cmdlist *node)
{
	if (ft_strncmp(node->cmd, "echo", math_min(ft_strlen(node->cmd), 4)) == 0)
		node->cmd_type = ECHO;
	else if (ft_strncmp(node->cmd, "env", \
		math_min(ft_strlen(node->cmd), 3)) == 0)
		node->cmd_type = ENV;
	else if (ft_strncmp(node->cmd, "export", \
		math_min(ft_strlen(node->cmd), 6)) == 0)
		node->cmd_type = EXPORT;
	else if (ft_strncmp(node->cmd, "exit", \
		math_min(ft_strlen(node->cmd), 4)) == 0)
		node->cmd_type = EXIT;
	else if (ft_strncmp(node->cmd, "pwd", \
		math_min(ft_strlen(node->cmd), 3)) == 0)
		node->cmd_type = PWD;
	else if (ft_strncmp(node->cmd, "unset", \
		math_min(ft_strlen(node->cmd), 5)) == 0)
		node->cmd_type = UNSET;
	else if (ft_strncmp(node->cmd, "cd", \
		math_min(ft_strlen(node->cmd), 2)) == 0)
		node->cmd_type = CD;
	else
		return (0);
	return (1);
}

char	*check_default_path(char *target, char *path)
{
	char	*temp;

	temp = ft_strjoin(path, target);
	free(path);
	path = NULL;
	if (access(temp, F_OK) == 0)
		return (temp);
	free(temp);
	temp = NULL;
	return (NULL);
}

static void	get_path(char **env_string, char ***path, t_vararr *env)
{
	*env_string = NULL;
	if (ft_getenv(env, "PATH") != NULL)
		*env_string = ft_strdup(ft_getenv(env, "PATH"));
	if (!*env_string)
		*path = NULL;
	else
		*path = ft_split(*env_string, ':');
	if (*path)
	{
		free(*env_string);
		*env_string = NULL;
	}
}

char	*is_executable(t_cmdlist *node, t_vararr *env)
{
	char	**path;
	char	*temp;
	int		i;

	get_path(&temp, &path, env);
	i = 0;
	while (path && path[i] != NULL)
	{
		temp = check_default_path(node->cmd, ft_strjoin(path[i], "/"));
		if (temp != NULL)
		{
			free_arr(path);
			return (temp);
		}
		i++;
	}
	free_arr(path);
	if (access(node->cmd, F_OK) == 0)
		return (ft_strdup(node->cmd));
	return (NULL);
}

void	check_cmd_type(t_cmdlist *node, t_vararr *env)
{
	char	*temp;
	int		i;

	i = 0;
	while (i < node->args->words_count)
		if (node->args->token_types[i++] == CMD)
			set_cmd(node, node->args->words[i - 1]);
	if (node->cmd == NULL)
	{
		node->cmd = ft_strdup("");
		node->cmd_type = NO_CMD;
		return ;
	}
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
