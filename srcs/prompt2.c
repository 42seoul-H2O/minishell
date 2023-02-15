/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:27 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/15 11:39:37 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	delete_after_pipe(t_cmdlist *node, int pipe_idx)
{
	int		i;

	i = pipe_idx;
	while (i < node->args->len)
	{
		delete_element(node->args, get_element(node->args, i));
	}
}

t_cmdlist	*list_maker(t_vararr *input, t_vararr *env)
{
	t_cmdlist	*result;
	int			i;
	// char		*temp;

	i = 0;
	result = make_new_node(NULL);
	copy_vararr(result->args, input, 0);
	// temp = get_element(input, i);
	// while (temp != NULL)
	// {
	// 	if (ft_strncmp(temp, "|", ft_strlen(temp)) == 0 \
	// 		&& get_element(input, i + 1) != NULL)
	// 	{
	// 		result = make_new_node(result);
	// 		copy_vararr(result->args, input, i + 1);
	// 		delete_after_pipe(result->prev, i);
	// 	}
	// 	i++;
	// 	temp = get_element(input, i);
	// }
	set_cmd(result, get_element(result->args, 0));
	check_cmd_type(result, env);
	return (list_reset_loc(result));
}

void	make_prompt(t_vararr *env)
{
	int			flag;
	char		*line;
	t_vararr	*input;
	t_cmdlist	*parsed;

	line = NULL;
	line = get_line(line);
	while (line != NULL)
	{
		flag = 0;
		input = parse(line, env);
		if (input->len != 0)
		{
			parsed = list_maker(input, env);
			execution(parsed, env);
			destroy_list(parsed);
		}
		destroy_arr(input);
		line = get_line(line);
	}
}
