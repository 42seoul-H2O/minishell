/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_syntax_err2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:56:57 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/20 21:26:46 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	catch_unmatching_quote_in_word(t_str *str, char *word);

void	catch_unmatching_quotes(t_parsed *parsed)
{
	size_t	i;
	t_str	temp;

	if (parsed->words_count == -1)
		return ;
	i = 0;
	while (parsed -> words[i])
	{
		temp.s = parsed -> words[i];
		temp.quote_flags = NULL;
		if (!catch_unmatching_quote_in_word(&temp, parsed -> words[i]))
		{
			parsed -> words_count = -1;
			free(temp.quote_flags);
			temp.quote_flags = NULL;
			return ;
		}
		free(temp.quote_flags);
		i++;
	}
}

static int	catch_unmatching_quote_in_word(t_str *str, char *word)
{
	size_t	i;
	size_t	single_quote_count;
	size_t	double_quote_count;

	i = 0;
	single_quote_count = 0;
	double_quote_count = 0;
	while (word[i])
	{
		if (word[i] == '\'' && !is_quoted(str, i))
			single_quote_count++;
		if (word[i] == '\"' && !is_quoted(str, i))
			double_quote_count++;
		i++;
	}
	if (single_quote_count % 2 || double_quote_count % 2)
		return (0);
	return (1);
}
