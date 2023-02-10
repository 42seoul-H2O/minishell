/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dollar_to_env.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:07:06 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/10 13:28:07 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "parser.h"
#include "vararr.h"

static t_dollar_sign	*init_dollar_sign(t_str *str, int word_i, char **envp, \
						int *visited);
static void				set_dollar_env_value(char *word, char **envp, \
						t_dollar_sign *dollar);
static int				set_dollar_indices(t_str *str, t_dollar_sign *dollar, \
						int *visited);
static	int				is_unallowed_char(char *word, int char_idx);

int	convert_single_dollar_to_env(t_str *str, int word_i, \
	char **envp, int *visited)
{
	t_dollar_sign	*dollar;

	dollar = init_dollar_sign(str, word_i, envp, visited);
	if (!dollar)
		return (0);
	replace_dollar_with_env(str, word_i, dollar, visited);
	free(dollar);
	return (1);
}

static t_dollar_sign	*init_dollar_sign(t_str *str, int word_i, char **envp, \
	int *visited)
{
	t_dollar_sign	*dollar;
	int				has_dollar_in_str;

	dollar = malloc(sizeof (t_dollar_sign) * 1);
	if (!dollar)
		builtin_exit(12);
	else if (!set_dollar_indices(str -> words[word_i], dollar, visited))
	{
		has_dollar_in_str = 0;
		return (NULL);
	}
	set_dollar_env_value(str -> words[word_i], envp, dollar);
	return (dollar);
}

static void	set_dollar_env_value(char *word, char **envp, t_dollar_sign *dollar)
{
	int		i;
	int		size;
	char	*name;

	i = 0;
	size = dollar -> last_idx - dollar -> first_idx;
	name = malloc(sizeof (char) * (size + 1));
	if (!name)
		builtin_exit(12);
	ft_strlcpy(name, word + dollar -> first_idx + 1, size + 1);
	dollar -> env_value = my_getenv(envp, name);
	free(name);
}

static int	set_dollar_indices(t_str *str, t_dollar_sign *dollar, \
	int *visited)
{
	int	i;
	int	is_dollar_found;

	i = 0;
	is_dollar_found = 0;
	dollar -> first_idx = -1;
	while (str -> s[i])
	{
		if (str -> s[i] == '$' && !visited[i])
		{
			dollar -> first_idx = i;
			is_dollar_found = 1;
		}
		else if (is_dollar_found && is_unallowed_char(str, i))
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

static	int	is_unallowed_char(char *word, int char_idx)
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
