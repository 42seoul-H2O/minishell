/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:46:36 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/12 13:08:56 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "builtin.h"

t_str	parse(char *input, t_vararr *env)
{
	t_str	str;

	init_t_str(&str, input);
	my_split(&str);
	convert_dollar_to_env(&str, env);
	return (str);
}
