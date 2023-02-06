/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vararr_oper1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:36:54 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/06 19:20:34 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vararr.h"

t_vararr	*make_new_arr(int size)
{
	t_vararr	*result;
	int			i;

	result = (t_vararr *)malloc(sizeof(t_vararr));
	if (!result)
		return (NULL);
	result->capacity = size;
	result->len = 0;
	result->arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!(result->arr))
	{
		free(result);
		return (NULL);
	}
	i = 0;
	while (i <= size)
		(result->arr)[i++] = NULL;
	return (result);
}

void	free_arr(char **arr)
{
	int		i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void	destroy_arr(t_vararr *varr)
{
	if (!varr)
		return ;
	free_arr(varr->arr);
	free(varr);
	varr = NULL;
}

int	realloc_2x_arr(t_vararr *varr)
{
	char	**buf;
	int		i;

	buf = (char **)ft_calloc(varr->capacity * 2 + 1, sizeof(char *));
	if (!buf)
		return (-1);
	i = 0;
	while (i < varr->len)
	{
		buf[i] = ft_strdup((varr->arr)[i]);
		i++;
	}
	free_arr(varr->arr);
	varr->arr = buf;
	varr->capacity *= 2;
	return (1);
}

char	**copy_arr(t_vararr *varr)
{
	char	**result;
	int		i;

	result = (char **)ft_calloc(varr->len + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < varr->len)
	{
		result[i] = ft_strdup((varr->arr)[i]);
		i++;
	}
	result[varr->len] = NULL;
	return (result);
}
