/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vararr_oper2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:37:11 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/06 13:50:06 by hyunjuki         ###   ########.fr       */
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
**** -1 : cannot find val
**** index : val's index of array

int	append_element(t_vararr *varr, char *val)
** append element of variable array
** varr = variable array
** val = string to append
** return
**** -1 : malloc error
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
**** -1 : ft_strjoin error
**** 0 : failed to update
**** 1 : update successfully
*/

char	*get_element(t_vararr *varr, int idx)
{
	if (!varr)
		return (NULL);
	if (idx >= varr->len)
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

	if (varr->capacity == varr->len)
		if (realloc_2x_arr(varr) == -1)
			return (-1);
	temp = ft_strdup(val);
	if (temp == NULL)
		return (-1);
	if (find_element(varr, val) != -1)
		return (0);
	(varr->arr)[varr->len] = temp;
	varr->len++;
	return (1);
}

int	update_element(t_vararr *varr, char *key, char *value)
{
	char	*target;
	char	*temp;
	int		i;

	temp = ft_strjoin(key, "=");
	if (temp == NULL)
		return (-1);
	target = ft_strjoin(temp, value);
	free(temp);
	if (target == NULL)
		return (-1);
	i = find_element(varr, key);
	if (i == -1)
		if (append_element(varr, target) != 1)
			return (0);
	free(varr->arr[i]);
	varr->arr[i] = target;
	return (1);
}