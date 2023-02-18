/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:55:10 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/18 17:55:07 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "constants.h"
#include "builtin.h"

static int	get_word_type(char **words, int idx);

int	get_token_type(char **words, int idx)
{
	int	optype;
	int	word_type;

	optype = get_optype(words[idx]);
	if (optype)
		return (optype);
	word_type = get_word_type(words, idx);
	return (word_type);
}

int	get_optype(char *word)
{
	if (ft_strlen(word) == 1)
	{
		if (word[0] == '|')
			return (PIPE);
		if (word[0] == '<')
			return (REDIR_IN);
		if (word[0] == '>')
			return (REDIR_OUT);
	}
	if (ft_strlen(word) == 2)
	{
		if (word[0] == '<' && word[1] == '<')
			return (HEREDOC);
		if (word[0] == '>' && word[1] == '>')
			return (APPEND);
	}
	return (0);
}

static int	get_word_type(char **words, int idx)
{
	if (is_redir_word(words, idx))
		return (REDIR_WORD);
	else if (is_cmd(words, idx))
		return (CMD);
	else
		return (ARG);
}

int	is_redir_word(char **words, int idx)
{
	int	cur_optype;
	int	pre_optype;

	cur_optype = get_optype(words[idx]);
	if (idx == 0)
		pre_optype = -1;
	else
		pre_optype = get_optype(words[idx - 1]);
	if ((pre_optype == REDIR_IN \
		|| pre_optype == REDIR_OUT \
		|| pre_optype == HEREDOC \
		|| pre_optype == APPEND) \
		&& !cur_optype)
		return (REDIR_WORD);
	return (0);
}
