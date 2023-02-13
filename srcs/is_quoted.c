/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quoted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:40:02 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/13 17:06:25 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	set_quote_flags(t_str *str);
static int	is_quote(char c, t_quote *quote);

int	is_quoted(t_str *str, int idx)
{
	if (idx == -1 || idx == (int) ft_strlen(str -> s))
		return (0);
	if (!str -> quote_flags)
		set_quote_flags(str);
	return (str -> quote_flags[idx]);
}

static void	set_quote_flags(t_str *str)
{
	int		i;
	int		*flags;
	t_quote	quote;

	quote.is_quoted = 0;
	flags = malloc(sizeof (int) * ft_strlen(str -> s));
	if (!flags)
		ft_exit(12);
	str -> quote_flags = flags;
	i = 0;
	while (str -> s[i])
	{
		if (is_quote(str -> s[i], &quote) && quote.is_quoted)
			quote.is_quoted = 0;
		else if (is_quote(str -> s[i], &quote))
		{
			quote.is_quoted = str -> s[i];
			flags[i] = 0;
			i++;
			continue ;
		}
		flags[i] = quote.is_quoted;
		i++;
	}
}

static int	is_quote(char c, t_quote *quote)
{
	if (!quote -> is_quoted && (c == '\'' || c == '\"'))
	{
		if (c == '\'')
			quote -> type = '\'';
		else
			quote -> type = '\"';
		return (1);
	}
	else
		return (c == quote -> type);
}
