/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vararr_oper3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:37:48 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/17 11:49:57 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vararr.h"

char	*ft_getenv(t_vararr *env, char *key)
{
	int		i;
	char	*temp;

	if (!env || !key)
		return (NULL);
	if (*key == '\0')
		return (NULL);
	i = find_element(env, key);
	if (i == -1)
		return (NULL);
	temp = get_element(env, i);
	temp = ft_strnstr(temp, "=", ft_strlen(temp));
	if (temp == NULL)
		return (NULL);
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



char	*join_key_value_string(char *key, char *value)
{
	char	*result;
	char	*temp;

	if (!value)
		return (ft_strdup(key));
	temp = ft_strjoin(key, "=");
	if (temp == NULL)
		return (NULL);
	result = ft_strjoin(temp, value);
	free(temp);
	return (result);
}
