/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:10:00 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/05 20:20:08 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"

void	init_t_str(t_str *str, char *s)
{
	str -> s = s;
	str -> delimiters = " \t";
	str -> included_delimiters = "<>|$";
	str -> quote_flags = NULL;
	set_word_count(str);
}
