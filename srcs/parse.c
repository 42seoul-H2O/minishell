/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:46:36 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/13 17:10:13 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_vararr	*parse(char *input, t_vararr *env)
{
	t_str		str;
	t_vararr	*result;
	int			i;

	init_t_str(&str, input);
	my_split(&str);
	convert_dollar_to_env(&str, env);
	remove_quotes(&str);
	result = make_new_arr(10);
	i = 0;
	while (i < str.word_count)
	{
		append_element(result, str.words[i]);
		i++;
	}
	destroy_t_str(&str);
	return (result);
}
