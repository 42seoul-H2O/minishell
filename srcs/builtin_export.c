/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:41:07 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/06 17:33:14 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	swap_element(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	quick_sort(char **arr, int left, int right)
{
	int	i;
	int	j;
	int	pivot;

	i = left;
	j = right;
	pivot = (left + right) / 2;
	while (i <= j)
	{
		while (ft_strncmp(arr[i], arr[pivot], ft_strlen(arr[i])) < 0)
			i++;
		while (ft_strncmp(arr[j], arr[pivot], ft_strlen(arr[i])) > 0)
			j--;
		if (i <= j)
			swap_element(&arr[i++], &arr[j--]);
	}
	if (left < j)
		quick_sort(arr, left, j);
	if (i < right)
		quick_sort(arr, i, right);
}

static t_vararr	*get_no_value(t_vararr *env)
{
	int			i;
	t_vararr	*result;

	result = make_new_arr(1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < env->len)
	{
		if (ft_strnstr((env->arr)[i], "=", ft_strlen((env->arr)[i])) == NULL)
		{
			append_element(result, env->arr[i]);
			delete_element(env, env->arr[i]);
		}
		i++;
	}
	return (result);
}

static int	sort_and_print(t_vararr *arr)
{
	char	**temp;

	temp = copy_arr(arr);
	if (!temp)
		return (-1);
	quick_sort(temp, 0, arr->len - 1);
	print_all_string("declare -x ", temp, 1, 1);
	free_arr(temp);
	temp = NULL;
	return (1);
}

static int	builtin_export_no_arg(t_vararr *env)
{
	int			i;
	t_vararr	*no_val;

	no_val = get_no_value(env);
	if (!no_val)
		return (-1);
	i = sort_and_print(env);
	if (i == -1)
		return (-1);
	i = sort_and_print(no_val);
	if (i == -1)
		return (-1);
	i = 0;
	while (i < no_val->len)
		append_element(env, (no_val->arr)[i++]);
	destroy_arr(no_val);
	no_val = NULL;
	return (1);
}

void	builtin_export(char **input, t_vararr *env)
{
	int		i;
	int		j;
	char	*temp;

	if (input[1] == NULL)
	{
		if (builtin_export_no_arg(env) == -1)
			builtin_exit(1);
		return ;
	}
	i = 1;
	while (input[i] != NULL)
	{
		if (ft_strchr(input[i], '=') == NULL)
			append_element(env, input[i]);
		else
		{
			j = ft_strchr(input[i], '=') - input[i];
			temp = ft_substr(input[i], 0, j);
			ft_setenv(env, temp, &input[i][j + 1], 1);
			free(temp);
		}
		i++;
	}
}
