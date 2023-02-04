/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_indices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:02:42 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/04 20:34:42 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_words(char const *s, char *delim, char *included_delim);

int	*get_token_indices(const char *s, char *delim, char *included_delim)
{
	int	i;
	int	j;
	int	*token_indices;
	int	*quote_flags;

	i = 0;
	j = 0;
	token_indices = malloc(sizeof (int) * \
		count_words(s, delim, included_delim));
	if (!token_indices)
		builtin_exit(12);
	quote_flags = get_quote_flags(s);
	while (s[i])
	{
		if ((is_delimiter(s, delim, i - 1) && !is_delimiter(s, delim, i)) || \
			is_special_delimiter(s[i], included_delim))
		{
			token_indices[j] = i;
			j++;
		}
		i++;
	}
	return (token_indices);
}

int	is_delimiter(char const *s, char *delim, int idx, int *quote_flags)
{
	size_t	i;

	i = 0;
	if (idx == -1 || !s[idx])
		return (1);
	while (delim[i])
	{
		if (s[idx] == delim[i] && !is_quoted(s, i, quote_flags))
			return (1);
		i++;
	}
	return (0);
}

int	is_special_delimiter(char *s, char *included_delim, \
	int idx, int *quote_flags)
{
	int	i;

	i = 0;
	while (included_delim[i])
	{
		if (c == included_delim[i] && !is_quoted(s, i, quote_flags))
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(char const *s, char *delim, char *included_delim)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!is_delimiter(s, delim, i)
			&& is_delimiter(s, delim, i + 1))
			count++;
		if (is_special_delimiter(s[i], included_delim))
			count++;
		i++;
	}
	return (count);
}
