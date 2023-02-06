/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vararr_oper3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:37:48 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/06 14:44:25 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vararr.h"

char	*ft_getenv(t_vararr *env, char *key)
{
	int		i;
	char	*temp;

	i = find_element(env, key);
	if (i == -1)
		return (NULL);
	temp = get_element(env, i);
	temp = ft_strnstr(temp, "=", ft_strlen(temp));
	return (++temp);
}

int	ft_setenv(t_vararr *env, char *key, char *value, int overwrite)
{
	int	i;

	i = find_element(env, key);
	if (overwrite == 1 || i == -1)
	{
		i = update_element(env, key, value);
		if (i > 0)
			i = 0;
		return (i);
	}
	return (0);
}

int	ft_unsetenv(t_vararr *env, char *key)
{
	int	result;

	result = delete_element(env, key);
	if (result == 1)
		result = 0;
	return (result);
}

void	print_all_string(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		printf("%s\n", arr[i++]);
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
