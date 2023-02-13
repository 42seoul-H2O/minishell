/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vararr_oper2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:37:11 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/13 16:55:01 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vararr.h"

/*
char	*get_element(t_vararr *varr, int idx)
** get element of variable array
** varr = variable array
** idx = index of array
** return
**** NULL : if invalid varr or idx >= varr's len
**** string(array[idx]) 

int	find_element(t_vararr *varr, char *val)
** find element(key or "key=value") of variable array
** varr = variable array
** val = string to find
** return
**** -1 : invalid varr or cannot find val
**** index : val's index of array

int	append_element(t_vararr *varr, char *val)
** append element of variable array
** varr = variable array
** val = string to append
** return
**** -1 : invalid varr or malloc error
**** 0 : array has 'val' already
**** 1 : append successfully

int	update_element(t_vararr *varr, char *key, char *value)
** update element of variable array
** find key and modify it to "key=value"
** if there is no key, append "key=value"
** varr = variable array
** key = key string to find
** value = value string to update
** return
**** -1 : invalid varr or ft_strjoin error
**** 0 : failed to update
**** 1 : update successfully or append successfully

int	delete_element(t_vararr *varr, char *key)
** delete element of variable array
** find key and delete it
** varr = variable array
** key = key string to delete
** return
**** -1 : invalid varr or failed to find key
**** 1 : delete successfully
*/

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
	int	i;

	i = 0;
	while (i < varr->len)
	{
		if (ft_strncmp(varr->arr[i], val, ft_strlen(val)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	append_element(t_vararr *varr, char *val)
{
	char	*temp;

	if (!varr)
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
