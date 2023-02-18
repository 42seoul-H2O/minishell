/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:46:36 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/18 19:05:27 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "builtin.h"

static int	get_word_count(char **words);

t_parsed	parse(char *input, t_vararr *env)
{
	t_str		str;
	t_parsed	parsed;

	init_t_str(&str, input);
	my_split(&str);
	merge_redir_tokens(&str);
	parsed.token_types = get_token_types(&str);
	convert_dollar_to_env(&str, env);
	remove_quotes(&str);
	parsed.words = str.words;
	parsed.words_count = get_word_count(str.words);
	destroy_t_str(&str);
	catch_parsing_err(&parsed);
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
	free(parsed -> words);
	free(parsed -> token_types);
}
