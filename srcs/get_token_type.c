/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:55:10 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/18 12:14:02 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "constants.h"
#include "builtin.h"

static int	get_word_type(char **words, int idx);

//TODO: << >> 와 < < > > 를 구분할 수 있어야 하는데, 지금 방법으로는 구분하지 않는다. 그렇기에,
	// 원래 문자열을 참고해서 리디렉션 연산자 쌍 사이에 다른 delimiter/special_delimiter가 있는지 체크해야한다.
	// 이러면 연산자가 3 개 같이 나올 때 처리가 될런지 모르겠네. "<< <", "<<<", "<<|<", "<|<", "< <"

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
		if (word[0] == '>' && word[2] == '>')
			return (APPEND);
	}
	return (0);
}

static int	get_word_type(char **words, int idx)
{
	if (is_redir_word(words, idx))
		return (REDIR_WORD);
	else if (is_cmd(words, idx))
		return (ARG);
	else
		return (CMD);
}

int	is_redir_word(char **words, int idx)
{
	int	pre_optype;

	if (idx == 0)
		pre_optype = -1;
	else
		pre_optype = get_optype(words[idx - 1]);
	if (pre_optype == REDIR_IN \
		|| pre_optype == REDIR_OUT)
		return (REDIR_WORD);
	return (0);
}
