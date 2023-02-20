/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:10:00 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/20 12:56:34 by hocsong          ###   ########seoul.kr  */
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
	str -> in_merge_count = 0;
	str -> out_merge_count = 0;
	set_word_count(str);
}

void	destroy_t_str(t_str *str)
{
	size_t	i;

	i = 0;
	free(str->quote_flags);
	free(str->token_indices);
}
