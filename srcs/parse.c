/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:46:36 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/17 21:39:02 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	set_token_type(t_parsed *p, int idx)
{
	if (p->words[idx][0] == '|')
		p->token_types[idx] = PIPE;
	else if (p->words[idx][0] == '>')
		p->token_types[idx] = REDIR_OUT;
	else if (p->words[idx][0] == '<')
		p->token_types[idx] = REDIR_IN;
	else if (idx == 0)
		p->token_types[idx] = CMD;
	else if (p->token_types[idx - 1] == PIPE)
		p->token_types[idx] = CMD;
	else
		p->token_types[idx] = ARG;
}

static int	copy_words(t_parsed *p, t_str *str)
{
	int	i;

	i = 0;
	p->word_count = str->word_count;
	p->words = ft_calloc(sizeof(char *), p->word_count + 1);
	p->token_types = ft_calloc(sizeof(int), p->word_count);
	if (!(p->words) || !(p->token_types))
		return (0);
	while (i < p->word_count)
	{
		p->words[i] = ft_strdup(str->words[i]);
		set_token_type(p, i);
		i++;
	}
	return (1);
}

t_parsed	*parse(char *input, t_vararr *env)
{
	t_str		str;
	t_parsed	*result;
	int			temp;

	init_t_str(&str, input);
	my_split(&str);
	convert_dollar_to_env(&str, env);
	remove_quotes(&str);
	result = malloc(sizeof(t_parsed));
	if (!result)
		return (NULL);
	temp = copy_words(result, &str);
	if (!temp)
		exit(11);
	destroy_t_str(&str);
	return (result);
}
