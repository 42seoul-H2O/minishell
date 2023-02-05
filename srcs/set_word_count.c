/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:22:41 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/05 11:25:14 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (is_special_delimiter(str, i))
			count++;
		i++;
	}
	str -> word_count = count;
}
