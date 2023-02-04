/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:11:02 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/04 14:14:22 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

typedef struct s_quote{
	int		idx;
	char	value;
}t_quote;

char	**tokenize(char const *s);
t_quote	find_quote(char const *s, char *c, int start_idx);
int		get_word_len(char const *s, char *c, int start_idx);

#endif