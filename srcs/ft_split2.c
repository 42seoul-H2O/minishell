/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:13:43 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/03 19:28:31 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_word_len(char const *s, char *c, int start_idx)
{
	int	i;
    int quote_idx;

	i = start_idx;
    quote_idx = -1;
    if (has_quote(s, c, start_idx) == NO_QUOTE)
    {
        while (s[i] && !is_delimiter(s, c, i))
		    i++;
        return (i - start_idx);
    }
    else
    {
        while(s[i])
        {
            if (s[i] == '\'' || s[i] == '\"')
                quote_idx = i;
            if (quote_idx != -1 && (s[i] == '\'' || s[i] == '\"'))
                return (i - start_idx);
            i++;
        }
    }
}

int  has_quote(char const *s, char *c, int start_idx)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == '\'')
            return (SINGLE_QUOTE);
        if (s[i] == '\"')
            return (DOUBLE_QUOTE);
        i++;
    }
    return (NO_QUOTE);
}