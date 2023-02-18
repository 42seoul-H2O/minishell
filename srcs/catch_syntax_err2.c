/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_parsing_err2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:56:57 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/18 19:03:59 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	catch_unmatching_quote_in_word(char *word);

void	catch_unmatching_quotes(t_parsed *parsed)
{
	size_t	i;

	if (parsed->words_count == -1)
		return ;
	i = 0;
	while (parsed -> words[i])
	{
		if (!catch_unmatching_quote_in_word(parsed -> words[i]))
		{
			parsed -> words_count = -1;
			return ;
		}
		i++;
	}
}

static int	catch_unmatching_quote_in_word(char *word)
{
	size_t	i;
	size_t	single_quote_count;
	size_t	double_quote_count;

	i = 0;
	single_quote_count = 0;
	double_quote_count = 0;
	while (word[i])
	{
		if (word[i] == '\'')
			single_quote_count++;
		if (word[i] == '\"')
			double_quote_count++;
		i++;
	}
	if (single_quote_count % 2 || double_quote_count % 2)
		return (0);
	return (1);
}
