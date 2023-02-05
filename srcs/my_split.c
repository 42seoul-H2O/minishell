/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:07:47 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/05 14:37:17 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "builtin.h"
#include "libft.h"

char	**my_split(char *s)
{
	int		i;
	char	*word;
	char	**words;
	t_str	str;

	i = 0;
	init_t_str(&str, s);
	words = malloc(sizeof (char *) * (str.word_count + 1));
	if (!words)
		builtin_exit(12);
	set_token_indices(&str);
	while (str.token_indices[i] != -1)
	{
		word = malloc(sizeof (char) * \
			(get_word_len(&str, str.token_indices[i]) + 1));
		ft_strlcpy(word, s + str.token_indices[i], \
			get_word_len(&str, str.token_indices[i]) + 1);
		words[i] = word;
		i++;
	}
	words[i] = NULL;
	return (words);
}
