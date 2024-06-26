/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:27 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/18 19:46:22 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parsed	*subparsed(t_parsed *input, int start, int end)
{
	t_parsed	*result;
	int			i;

	result = malloc(sizeof(t_parsed));
	if (!result)
		ft_exit(11);
	result->words_count = end - start + 1;
	if (result->words_count <= 0)
		ft_exit(11);
	result->words = ft_calloc(sizeof(char *), result->words_count + 1);
	result->token_types = ft_calloc(sizeof(int), result->words_count);
	if (!(result->words) || !(result->token_types))
		ft_exit(11);
	i = 0;
	while (i < result->words_count)
	{
		result->token_types[i] = input->token_types[start + i];
		result->words[i] = ft_strdup(input->words[start + i]);
		i++;
	}
	return (result);
}

t_cmdlist	*list_maker(t_parsed *input, t_vararr *env, int *last_pipe)
{
	t_cmdlist	*result;
	int			i;

	i = 0;
	*last_pipe = -1;
	result = make_new_node(NULL);
	if (!result)
		ft_exit(11);
	while (i < input->words_count)
	{
		if (input->token_types[i] == PIPE)
		{
			result = make_new_node(result);
			if (!result)
				ft_exit(11);
			result->prev->args = subparsed(input, *last_pipe + 1, i - 1);
			check_cmd_type(result->prev, env);
			*last_pipe = i;
		}
		i++;
	}
	return (result);
}

void	parsed_delete_idx(t_parsed *p, int idx)
{
	int	i;

	if (!p)
		return ;
	if (idx < 0 || idx >= p->words_count)
		return ;
	free(p->words[idx]);
	i = idx + 1;
	while (i < p->words_count)
	{
		p->token_types[i - 1] = p->token_types[i];
		p->words[i - 1] = p->words[i];
		i++;
	}
	p->token_types[p->words_count - 1] = -1;
	p->words[p->words_count - 1] = NULL;
	p->words_count--;
}

void	make_prompt(t_vararr *env)
{
	int			pipe;
	char		*line;
	t_parsed	*input;
	t_cmdlist	*node;

	line = NULL;
	line = get_line(line);
	while (line != NULL)
	{
		input = parse(line, env);
		if (input->words_count == -1)
			prt_syntax_error();
		if (input->words_count > 0)
		{
			node = list_maker(input, env, &pipe);
			node->args = subparsed(input, pipe + 1, input->words_count - 1);
			check_cmd_type(node, env);
			execution(list_reset_loc(node), env);
			destroy_list(list_reset_loc(node));
		}
		destroy_parsed(input);
		line = get_line(line);
	}
}

void	prt_syntax_error(void)
{
	ft_putstr_fd("h2osh: syntax error\n", 2);
	g_exit_code = 2;
}
