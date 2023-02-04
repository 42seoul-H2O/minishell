/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:51:57 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/04 20:35:26 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_word_len(const char *s, int start_idx, char *delim, \
	char *included_delim)
{
	int	i;
	int	*quote_flags;

	i = start_idx;
	quote_flags = get_quote_flags(s);
	if (is_special_delimiter(s, included_delim, i, quote_flags) && !quote_flags[i])
		return (1);
	while (s[i])
	{
		if ((is_special_delimiter(s[i], included_delim) && \
			!is_quoted(s, i, quote_flags)) || (is_delimiter(s[i], delim, i) && \
			!is_quoted(s, i, quote_flags)))
			return (i - start_idx);
		i++;
	}
	return (i - start_idx - 1);
}
