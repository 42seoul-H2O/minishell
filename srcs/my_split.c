/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:07:47 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/13 17:06:25 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**my_split(t_str *str)
{
	int		i;
	char	*word;
	char	**words;

	i = 0;
	words = malloc(sizeof (char *) * (str -> word_count + 1));
	if (!words)
		ft_exit(12);
	set_token_indices(str);
	while (str -> token_indices[i] != -1)
	{
		word = malloc(sizeof (char) * \
			(get_word_len(str, str -> token_indices[i]) + 1));
		ft_strlcpy(word, str -> s + str -> token_indices[i], \
			get_word_len(str, str -> token_indices[i]) + 1);
		words[i] = word;
		i++;
	}
	words[i] = NULL;
	str -> words = words;
	return (words);
}
