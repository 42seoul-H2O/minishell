/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quoted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:40:02 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/05 12:30:25 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

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
	flags = malloc(sizeof (char) * ft_strlen(str -> s));
	if (!flags)
		builtin_exit(12);
	i = 0;
	while (str -> s[i])
	{
		if (is_quote(str -> s[i], &quote) && quote.is_quoted)
			quote.is_quoted = 0;
		else if (is_quote(str -> s[i], &quote) && !quote.is_quoted)
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
