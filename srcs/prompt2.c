/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:27 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/13 17:41:43 by hyunjuki         ###   ########.fr       */
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
			flag += exec_builtins(parsed, env);
			if (flag == 0)
				flag += exec_bin(parsed, env);
			if (flag == 0)
				printf("h2osh: %s: command not found\n", parsed->cmd);
			destroy_list(parsed);
		}
		destroy_arr(input);
		line = get_line(line);
	}
}
