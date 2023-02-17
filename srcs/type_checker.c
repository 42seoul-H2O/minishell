/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:57:37 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/17 14:13:49 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_cmdlist *node)
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

char	*is_executable(t_cmdlist *node, t_vararr *env)
{
	char	**path;
	char	*temp;
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
	while (i < node->args->word_count)
	{
		if (node->args->token_types[i] == CMD)
			set_cmd(node, node->args->words[i]);
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