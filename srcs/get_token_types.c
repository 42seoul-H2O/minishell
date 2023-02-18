/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:42:34 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/18 17:55:59 by hocsong          ###   ########seoul.kr  */
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
