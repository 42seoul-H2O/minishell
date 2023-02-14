/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_word_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:22:41 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/15 00:33:02 by hyunjuki         ###   ########.fr       */
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
		if (!is_delimiter(str, i)
			&& is_delimiter(str, i + 1))
			count++;
		else if (is_special_delimiter(str, i))
			count++;
		i++;
	}
	str -> word_count = count;
}
