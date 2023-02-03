/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:13:43 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/03 20:00:06 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_word_len(char const *s, char *c, int start_idx)
{
	int	i;
    int should_detect_delimiter;
    int *quote_idx_val;

	i = start_idx;
    quote_idx_val = find_quote(s, c, start_idx);
    if (quote_idx_val[0] == NO_QUOTE)
    {
        while (s[i] && !is_delimiter(s, c, i))
		    i++;
        free(quote_idx_val);
        return (i - start_idx);
    }
    else
    {
        should_detect_delimiter = SWITCH_OFF;
        i = quote_idx_val[0] + 1;
        while (s[i])
        {
            if (is_quote(s[i]))
                should_detect_delimiter = SWITCH_ON;
            i++;
        }
    }
}

int  *find_quote(char const *s, char *c, int start_idx)
{
    int i;
    int *idx_value;

    i = 0;
    idx_value = malloc(sizeof (int) * 2);
    if (!idx_value)
        exit (1); // 적절한 코드로 바꾸자.
    while (s[i])
    {
        if (s[i] == '\'' || s[i] == '\"')
        {
            idx_value[0] = i;
            if (s[i] == '\'')
                idx_value[1] = '\'';
            if (s[i] == '\"')
                idx_value[1] = '\"';
            return (idx_value);
        }
        i++;
    }
    idx_value[0] == NO_QUOTE;
    return (idx_value);
}

