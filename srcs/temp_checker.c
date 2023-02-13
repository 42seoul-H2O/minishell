/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:57:37 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/13 15:01:06 by hyunjuki         ###   ########.fr       */
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

char	*is_executable(t_cmdlist *node, t_vararr *env)
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

void	check_cmd_type(t_cmdlist *node, t_vararr *env)
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

void	copy_vararr(t_vararr *dst, t_vararr *src)
{
	int	i;

	i = 0;
	while (i < src->len)
	{
		append_element(dst, get_element(src, i));
		i++;
	}
}
