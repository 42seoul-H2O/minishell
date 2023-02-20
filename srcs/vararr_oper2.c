/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vararr_oper2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:37:11 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/20 15:46:35 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "vararr.h"

char	*get_element(t_vararr *varr, int idx)
{
	if (!varr)
		return (NULL);
	if (idx >= varr->len || idx < 0)
		return (NULL);
	return ((varr->arr[idx]));
}

int	find_element(t_vararr *varr, char *val)
{
	int		i;
	char	*key;

	i = 0;
	while (i < varr->len)
	{
		key = NULL;
		if (ft_strchr(varr->arr[i], '=') == NULL)
			key = ft_strdup(varr->arr[i]);
		else
			key = ft_substr(varr->arr[i], 0, \
				ft_strchr(varr->arr[i], '=') - varr->arr[i]);
		if (key == NULL)
			return (-1);
		if (ft_strncmp(key, val, \
			math_min(ft_strlen(key), ft_strlen(val))) == 0)
		{
			free(key);
			return (i);
		}
		if (key)
			free(key);
		i++;
	}
	return (-1);
}

int	append_element(t_vararr *varr, char *val)
{
	char	*temp;

	if (!varr || !val)
		return (-1);
	if (varr->capacity == varr->len)
		if (realloc_arr(varr, 2.0) == -1)
			return (-1);
	if (find_element(varr, val) != -1)
		return (0);
	temp = ft_strdup(val);
	if (temp == NULL)
		return (-1);
	(varr->arr)[varr->len] = temp;
	varr->len++;
	return (1);
}

int	update_element(t_vararr *varr, char *key, char *value)
{
	char	*target;
	int		i;

	if (!varr || !key)
		return (-1);
	target = join_key_value_string(key, value);
	if (target == NULL)
		return (-1);
	i = find_element(varr, key);
	if (i == -1)
	{
		i = append_element(varr, target);
		free(target);
		if (i != 1)
			return (0);
		return (1);
	}
	free(varr->arr[i]);
	varr->arr[i] = target;
	return (1);
}

int	delete_element(t_vararr *varr, char *key)
{
	int	i;
	int	j;

	if (!varr || varr->len == 0)
		return (-1);
	i = find_element(varr, key);
	if (i == -1)
		return (-1);
	free(varr->arr[i]);
	j = i + 1;
	while (varr->arr[j] != NULL)
		varr->arr[i++] = varr->arr[j++];
	varr->arr[i] = NULL;
	varr->len -= 1;
	if (varr->len * 3 < varr->capacity)
		if (realloc_arr(varr, 0.5) == -1)
			return (-1);
	return (1);
}
