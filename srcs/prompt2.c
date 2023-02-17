/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:27 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/17 16:01:43 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_parsed(t_parsed *p)
{
	int	i;

	if (!p)
		return ;
	if (p->words)
		free_arr(p->words);
	if (p->token_types)
		free(p->token_types);
	free(p);
	p = NULL;
}

t_parsed	*subparsed(t_parsed *input, int start, int end)
{
	t_parsed	*result;
	int			i;

	result = malloc(sizeof(t_parsed));
	if (!result)
		ft_exit(11);
	result->word_count = end - start + 1;
	if (result->word_count <= 0)
		ft_exit(11);
	result->words = malloc (sizeof(char *) * result->word_count + 1);
	result->token_types = malloc(sizeof(int) * result->word_count);
	if (result->words || result->token_types)
		ft_exit(11);
	i = 0;
	while (i < result->word_count)
	{
		result->token_types[i] = input->token_types[i];
		result->words[i] = ft_strdup(input->words[i]);
		i++;
	}
	return (result);
}

t_cmdlist	*list_maker(t_parsed *input, t_vararr *env)
{
	t_cmdlist	*result;
	int			i;
	int			last_pipe;

	i = 0;
	last_pipe = -1;
	result = make_new_node(NULL);
	if (!result)
		ft_exit(11);
	while (i < input->word_count)
	{
		if (ft_strncmp(input->words[i], "|", ft_strlen(input->words[i]) == 0))
		{
			result = make_new_node(result);
			if (!result)
				ft_exit(11);
			result->args = subparsed(input, last_pipe + 1, i - 1);
			check_cmd_type(result->prev, env);
			last_pipe = i;
		}
		i++;
	}
	return (list_reset_loc(result));
}

void	parsed_delete_idx(t_parsed *p, int idx)
{
	int	i;

	if (!p)
		return ;
	if (idx < 0 || idx >= p->word_count)
		return ;
	free(p->words[idx]);
	i = idx + 1;
	while (i < p->word_count)
	{
		p->token_types[i - 1] = p->token_types[i];
		p->words[i - 1] = p->words[i];
	}
	p->token_types[p->word_count - 1] = -1;
	p->words[p->word_count - 1] = NULL;
	p->word_count--;
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
		if (input != NULL && input->word_count != 0)
		{
			head = list_maker(input, env); //parsed 구조체를 활용하여 리스트를 만들기
			if (head->next == NULL)
			{
				head->args = subparsed(input, 0, input->word_count - 1);
				check_cmd_type(head, env);
			}
			execution(head, env);
			destroy_list(list_reset_loc(head));
		}
		destroy_parsed(input);
		line = get_line(line);
	}
}
