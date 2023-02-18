/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:42:34 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/17 16:35:31 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "builtin.h"

int	*get_token_types(t_str *str)
{
	int		*token_types;
	size_t	i;

	i = 0;
	while (str -> words[i])
		i++;
	token_types = malloc(sizeof (int) * (i + 1));
	i = 0;
	if (!token_types)
		builtin_exit(12);
	while (str -> words[i])
	{
		token_types[i] = get_token_type(str -> words, i);
		i++;
	}
	return (token_types);
}

// static t_str	partial_cp_t_str(t_str *str)
// {
// 	t_str	new_str;

// 	new_str.s = str -> s;
// 	new_str.words = cp_tokens(str -> words);
// 	return (new_str);
// }

// static char	**cp_tokens(char **tokens)
// {
// 	size_t	i;
// 	char	**new_tokens;

// 	i = 0;
// 	while (tokens[i])
// 		i++;
// 	new_tokens = malloc(sizeof (char *) * i + 1);
// 	if (!new_tokens)
// 		builtin_exit(12);
// 	i = 0;
// 	while (tokens[i])
// 	{
// 		new_tokens[i] = tokens[i];
// 		i++;
// 	}
// 	return (new_tokens);
// }
