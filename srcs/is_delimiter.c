/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_delimiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:08:35 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/05 15:01:55 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_delimiter(t_str *str, int idx)
{
	int	i;

	i = 0;
	if (idx == -1 || !str -> s[idx])
		return (1);
	while (str -> delimiters[i])
	{
		if (str -> s[idx] == str -> delimiters[i] && !is_quoted(str, idx))
			return (1);
		i++;
	}
	return (0);
}

int	is_special_delimiter(t_str *str, int idx)
{
	int	i;

	i = 0;
	while (str -> included_delimiters[i])
	{
		if (str -> s[idx] == str -> included_delimiters[i] && \
			!is_quoted(str, idx))
			return (1);
		i++;
	}
	return (0);
}
