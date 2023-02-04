/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quote_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:40:02 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/04 20:20:09 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

static int	is_quote(char c, t_quote *quote);

int	is_quoted(const char *s, int idx, int *quote_flags)
{
	if (idx == -1 || idx == ft_strlen(s))
		return (0);
	return (quote_flags[idx]);
}

int	*get_quote_flags(const char *s)
{
	int		i;
	int		*flags;
	t_quote	quote;

	quote.is_quoted = 0;
	flags = malloc(sizeof (char) * ft_strlen(s));
	if (!flags)
		builtin_exit(12);
	i = 0;
	while (s[i])
	{
		if (is_quote(s[i], &quote) && quote.is_quoted)
			quote.is_quoted = 0;
		else if (is_quote(s[i], &quote) && !quote.is_quoted)
			quote.is_quoted = 1;
		flags[i] = quote.is_quoted;
		i++;
	}
	return (flags);
}

static int	is_quote(char c, t_quote *quote)
{
	if (!quote -> is_quoted)
		return (c == '\'' || c == '\"');
	else
		return (c == quote -> type);
}
