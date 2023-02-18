/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_type2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:32:01 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/18 16:19:52 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "constants.h"

static int	find_pipe_or_initial_word(char **words, int idx);
static int	find_pipe_or_last_word(char **words, int idx);

int	is_cmd(char **words, int idx)
{
	int	is_op;
	int	idx_from;
	int	idx_to;

	idx_from = find_pipe_or_initial_word(words, idx) + 1;
	idx_to = find_pipe_or_last_word(words, idx) - 1;
	is_op = 1;
	while (idx_from <= idx && idx_from <= idx_to)
	{
		is_op = get_optype(words[idx_from]);
		if (!is_op && !is_redir_word(words, idx_from))
		{
			if (idx_from < idx)
				return (0);
			else
				return (1);
		}
		idx_from++;
	}
	return (0);
}

static int	find_pipe_or_initial_word(char **words, int idx)
{
	while (0 <= idx && get_optype(words[idx]) != PIPE)
		idx--;
	return (idx);
}

static int	find_pipe_or_last_word(char **words, int idx)
{
	while (words[idx] && get_optype(words[idx]) != PIPE)
		idx++;
	return (idx);
}
