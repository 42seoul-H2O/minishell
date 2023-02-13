/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token_indices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:02:42 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/13 17:06:25 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "builtin.h"

void	set_token_indices(t_str *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	str -> token_indices = malloc(sizeof (int) * \
		(str -> word_count + 1));
	if (!(str -> token_indices))
		ft_exit(12);
	while (str -> s[i])
	{
		if ((is_delimiter(str, i - 1) && \
			!is_delimiter(str, i)) || \
			is_special_delimiter(str, i))
		{
			str -> token_indices[j] = i;
			j++;
		}
		i++;
	}
	str -> token_indices[j] = -1;
}
