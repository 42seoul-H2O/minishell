/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:55:10 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/15 15:48:06 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "constants.h"

static int	get_optype(char *word);

//TODO: << >> 와 < < > > 를 구분할 수 있어야 하는데, 지금 방법으로는 구분하지 않는다. 그렇기에,
	// 원래 문자열을 참고해서 

int	get_token_type(char **words, int idx)
{
	int	optype;
	int	word_type;

	optype = get_optype(words[idx]);
	word_type = get_word_type(words, idx);
	if (optype)
		return (optype);
	else if (word_type)
		return (word_type);
	return (0);
}

static int	get_optype(char *word)
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
	return (0);
}

static int	get_word_type(char **words, int idx)
{
	int	cur_optype;
	int	pre_optype;

	cur_optype = get_optype(words[idx]);
	if (idx == 0)
		pre_optype = -1;
	else
		pre_optype = get_optype(words[idx - 1]);
	if (pre_optype == -1 || pre_optype == REDIR_IN \
		|| pre_optype == REDIR_OUT)
		return (REDIR_WORD);
	if (has_cmd(idx))
		return (ARG);
	if (!has_cmd(idx))
		return (CMD);
	return (0);
}
