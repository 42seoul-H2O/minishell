/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dollar_to_env.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:07:06 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/17 21:38:29 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "parser.h"
#include "vararr.h"

static t_dollar_sign	*init_dollar_sign(t_str *str, int word_i, \
						t_vararr *env, t_visited *visited);
static void				set_dollar_env_value(char *word, t_vararr *env, \
						t_dollar_sign *dollar);
static int				set_dollar_indices(char *word, t_dollar_sign *dollar, \
						t_visited *visited);
static int				is_dollar_single_quoted(t_str *str, int word_i, \
						int dollar_i);

int	convert_single_dollar_to_env(t_str *str, int word_i, \
	t_vararr *env, t_visited *visited)
{
	t_dollar_sign	*dollar;

	dollar = init_dollar_sign(str, word_i, env, visited);
	if (!dollar)
		return (0);
	if (is_dollar_single_quoted(str, word_i, dollar -> first_idx))
	{
		set_visited(visited, dollar -> first_idx);
		free(dollar);
		return (1);
	}
	replace_dollar_with_env(str, word_i, dollar, visited);
	free(dollar);
	return (1);
}

static int	is_dollar_single_quoted(t_str *str, int word_i, int dollar_i)
{
	t_str	temp;

	init_t_str(&temp, str -> words[word_i]);
	if (is_quoted(&temp, dollar_i) == '\'')
	{
		free(temp.quote_flags);
		return (1);
	}
	free(temp.quote_flags);
	return (0);
}

static t_dollar_sign	*init_dollar_sign(t_str *str, int word_i, \
						t_vararr *env, t_visited *visited)
{
	t_dollar_sign	*dollar;

	dollar = malloc(sizeof (t_dollar_sign) * 1);
	if (!dollar)
		exit(12);
	else if (!set_dollar_indices(str -> words[word_i], dollar, visited))
	{
		free(dollar);
		return (NULL);
	}
	set_dollar_env_value(str -> words[word_i], env, dollar);
	return (dollar);
}

static void	set_dollar_env_value(char *word, t_vararr *env, \
			t_dollar_sign *dollar)
{
	int		size;
	char	*name;

	size = dollar -> last_idx - dollar -> first_idx;
	name = malloc(sizeof (char) * (size + 1));
	if (!name)
		exit(12);
	ft_strlcpy(name, word + dollar -> first_idx + 1, size + 1);
	dollar -> env_value = ft_getenv(env, name);
	if (!dollar -> env_value)
		dollar -> env_value = "";
	free(name);
}

static int	set_dollar_indices(char *word, t_dollar_sign *dollar, \
	t_visited *visited)
{
	int	i;
	int	is_dollar_found;

	i = 0;
	is_dollar_found = 0;
	dollar -> first_idx = -1;
	while (word[i])
	{
		if (word[i] == '$' && !is_visited(visited, i) && !is_dollar_found)
		{
			dollar -> first_idx = i;
			is_dollar_found = 1;
		}
		else if (is_dollar_found && is_unallowed_char(word, i))
		{
			dollar -> last_idx = i - 1;
			return (1);
		}
		i++;
	}
	if (dollar -> first_idx != -1)
		dollar -> last_idx = i - 1;
	if (dollar -> first_idx != -1)
		return (1);
	return (0);
}
