/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:27 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/17 12:15:04 by hyunjuki         ###   ########.fr       */
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

	i = 0;
	result = make_new_node(NULL);
	copy_vararr(result->args, input, 0);
	set_cmd(result, get_element(result->args, 0));
	check_cmd_type(result, env);
	return (list_reset_loc(result));
}

void	make_prompt(t_vararr *env)
{
	int			flag;
	char		*line;
	t_parsed	*input;
	t_cmdlist	*head;

	line = NULL;
	line = get_line(line);
	while (line != NULL)
	{
		flag = 0;
		input = parse(line, env); //parsed 구조체에 내용이 채워져서 들어올 예정
		if (input->word_count != 0)
		{
			head = list_maker(input, env); //parsed 구조체를 활용하여 리스트를 만들기
			execution(head, env);
			destroy_list(head);
		}
		destroy_arr(input); //destory_parsed로 교체
		line = get_line(line);
	}
}
