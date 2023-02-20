/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:46:36 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/20 18:04:16 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	get_word_count(char **words);

t_parsed	*parse(char *input, t_vararr *env)
{
	t_str		str;
	t_parsed	*parsed;

	init_t_str(&str, input);
	my_split(&str);
	merge_redir_tokens(&str);
	parsed = malloc(sizeof(t_parsed));
	if (!parsed)
		return (NULL);
	parsed->token_types = get_token_types(&str);
	convert_dollar_to_env(&str, env);
	parsed->words = str.words;
	parsed->words_count = get_word_count(str.words);
	catch_syntax_err(parsed);
	remove_quotes(&str);
	parsed->words = str.words;
	destroy_t_str(&str);
	return (parsed);
}

static int	get_word_count(char **words)
{
	size_t	i;

	i = 0;
	while (words[i])
		i++;
	return (i);
}

void	destroy_parsed(t_parsed *parsed)
{
	if (!parsed)
		return ;
	free_arr(parsed->words);
	free(parsed->token_types);
	free(parsed);
}
