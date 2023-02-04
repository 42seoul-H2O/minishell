/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:13:43 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/04 13:29:02 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_word_len(char const *s, char *c, int start_idx)
{
	int		i;
	int 	should_detect_delimiter;
	t_quote	quote;

	i = start_idx;
	quote = find_quote(s, c, start_idx);
	if (quote.idx == NO_QUOTE)
	{
		while (s[i] && !is_delimiter(s, c, i))
			i++;
		return (i - start_idx);
	}
	else
	{
		should_detect_delimiter = OFF;
		i = quote.idx + 1;
		while (s[i])
		{
			if (s[i] == quote.value )
				should_detect_delimiter = ON;
			if (should_detect_delimiter == ON && is_delimiter(s, c, i))
				return (i - start_idx);
			i++;
		}
	}
}

t_quote	find_quote(char const *s, char *c, int start_idx)
{
	int		i;
	t_quote	quote;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			quote.idx = i;
			if (s[i] == '\'')
				quote.value = '\'';
			if (s[i] == '\"')
				quote.value = '\"';
			return (quote);
		}
		i++;
	}
	quote.idx == NO_QUOTE;
	return (quote);
}
