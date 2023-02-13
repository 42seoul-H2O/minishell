/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:51:57 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/05 14:07:34 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_word_len(t_str *str, int start_idx)
{
	int	i;

	i = start_idx;
	if (is_special_delimiter(str, i))
		return (1);
	while (str -> s[i])
	{
		if (is_special_delimiter(str, i) || \
			is_delimiter(str, i))
			return (i - start_idx);
		i++;
	}
	return (i - start_idx);
}
