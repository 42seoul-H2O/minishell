/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:46:36 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/12 10:01:52 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_str	*parse(char *input, t_vararr *env)
{
	t_str	*str;

	str = malloc(sizeof (t_str));
	if (!str)
		builtin_exit(12);
	str -> s = input;
	my_split(str);
	convert_dollar_to_env(str, env);
	return (str);
}
