/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:11:02 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/04 17:40:51 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

typedef struct s_quote{
	int		idx;
	char	value;
}t_quote;

char	**tokenize(char const *s);
char	**my_split(char const *s, char *c, char *special_delimiter);
t_quote	find_quote(char const *s);
int		get_word_len(char const *s, char *c, int start_idx);
int		is_special_delimiter(char c, char *special_delimiters);
int		is_delimiter(char const *s, char *c, int idx);

#endif