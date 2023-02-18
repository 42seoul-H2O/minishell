/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_word_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:22:41 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/15 12:17:26 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	set_word_count(t_str *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str -> s[i])
	{
		if ((is_delimiter(str, i - 1) || is_special_delimiter(str, i - 1))
			&& !is_delimiter(str, i))
			count++;
		else if (is_special_delimiter(str, i))
			count++;
		i++;
	}
	str -> word_count = count;
}
