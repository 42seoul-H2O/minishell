/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:55:08 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/13 15:01:00 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmdlist	*list_maker(t_vararr *input, t_vararr *env)
{
	t_cmdlist	*result;

	result = make_new_node(NULL);
	copy_vararr(result->args, input);
	set_cmd(result, get_element(result->args, 0));
	check_cmd_type(result, env);
	return (result);
}

t_vararr	*parse_input(char *s, char c)
{
	char		**splited;
	t_vararr	*result;
	int			i;

	i = 0;
	result = make_new_arr(10);
	if (!result)
		return (NULL);
	splited = ft_split(s, c);
	while (splited[i] != NULL)
	{
		append_element(result, splited[i]);
		i++;
	}
	free_arr(splited);
	return (result);
}
