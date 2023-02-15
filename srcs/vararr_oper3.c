/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vararr_oper3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:37:48 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/14 13:49:35 by hyunjuki         ###   ########.fr       */
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

void	print_all_string(char *prefix, char **arr, int value_quote, int no_val)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] != NULL)
	{
		j = -1;
		if (no_val == 1 || ft_strnstr(arr[i], "=", ft_strlen(arr[i])) != NULL)
		{
			if (prefix != NULL)
				printf("%s", prefix);
			if (ft_strnstr(arr[i], "=", ft_strlen(arr[i])) != NULL)
				j = (ft_strnstr(arr[i], "=", ft_strlen(arr[i])) - arr[i]);
			if (!value_quote)
				printf("%s", arr[i]);
			else if (j >= 0)
				printf("%.*s\"%s\"", j + 1, arr[i], &arr[i][j + 1]);
			else
				printf("%.*s", j, arr[i]);
			printf("\n");
		}
		i++;
	}
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
