/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:10:00 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/13 14:42:28 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"

void	init_t_str(t_str *str, char *s)
{
	str -> s = s;
	str -> delimiters = " \t";
	str -> included_delimiters = "<>|";
	str -> quote_flags = NULL;
	set_word_count(str);
}

void	destroy_t_str(t_str *str)
{
	size_t	i;

	i = 0;
	free(str->quote_flags);
	while (str->words[i])
	{
		free(str->words[i]);
		i++;
	}
	free(str->words);
	free(str->token_indices);
}
