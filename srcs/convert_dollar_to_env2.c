/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dollar_to_env2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:09:04 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/18 16:02:28 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "builtin.h"
#include "vararr.h"

static void	replace_dollar(t_str *str, int word_i, \
			t_dollar_sign *dollar);
static void	replace_dollar_question(t_str *str, int word_i, \
			t_dollar_sign *dollar);

void	convert_dollar_to_env(t_str *str, t_vararr *env)
{
	t_visited	*visited;
	size_t		i;

	i = 0;
	while (str -> words[i])
	{
		visited = init_visited();
		while (convert_single_dollar_to_env(str, i, env, visited))
			;
		destroy_visited(visited);
		i++;
	}
}

void	replace_dollar_with_env(t_str *str, int word_i, t_dollar_sign *dollar, \
	t_visited *visited)
{
	if (str->words[word_i][dollar->first_idx + 1] && \
		str->words[word_i][dollar->first_idx + 1] == '?')
		replace_dollar_question(str, word_i, dollar);
	if (dollar -> first_idx == dollar -> last_idx)
	{
		set_visited(visited, dollar->first_idx);
		return ;
	}
	replace_dollar(str, word_i, dollar);
}

int	is_unallowed_char(char *word, int char_idx)
{
	char	c;

	c = word[char_idx];
	if (word[char_idx - 1] == '$')
		return (!(('a' <= c && c <= 'z') || \
			('A' <= c && c <= 'Z') || c == '_'));
	else
		return (!(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || \
			('0' <= c && c <= '9') || c == '_'));
}

static void	replace_dollar(t_str *str, int word_i, \
			t_dollar_sign *dollar)
{
	char	*dest1;
	char	*dest2;
	char	*dest3;

	dest1 = malloc(sizeof (char) * (dollar -> first_idx) + 1);
	if (!dest1)
		exit(12);
	ft_strlcpy(dest1, str -> words[word_i], dollar -> first_idx + 1);
	dest2 = ft_strjoin(dest1, dollar -> env_value);
	if (!dest2)
		exit(12);
	free(dest1);
	dest3 = ft_strjoin(dest2, str -> words[word_i] + dollar -> last_idx + 1);
	if (!dest3)
		exit(12);
	free(dest2);
	free(str -> words[word_i]);
	str -> words[word_i] = dest3;
}

static void	replace_dollar_question(t_str *str, int word_i, \
			t_dollar_sign *dollar)
{
	char	*dest1;
	char	*dest2;
	char	*dest3;
	char	*exit_code;

	dest1 = malloc(sizeof (char) * (dollar -> first_idx) + 1);
	if (!dest1)
		builtin_exit(12);
	ft_strlcpy(dest1, str -> words[word_i], dollar -> first_idx + 1);
	exit_code = ft_itoa(g_exit_code);
	dest2 = ft_strjoin(dest1, exit_code);
	free(exit_code);
	if (!dest2)
		builtin_exit(12);
	free(dest1);
	dest3 = ft_strjoin(dest2, str -> words[word_i] + dollar -> last_idx + 2);
	if (!dest3)
		builtin_exit(12);
	free(dest2);
	free(str -> words[word_i]);
	str -> words[word_i] = dest3;
}
