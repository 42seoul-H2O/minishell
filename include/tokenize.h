/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:11:02 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/04 20:36:17 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

typedef struct s_quote{
	int		is_quoted;
	char	type;
}t_quote;

char	**tokenize(char const *s);
int		*get_quote_flags(const char *s);
int		is_quoted(const char *s, int idx, int *quote_flags);
int		get_word_len(char const *s, char *c, int start_idx);
int		is_special_delimiter(char *s, char *included_delim, \
		int idx, int *quote_flags);
int		is_delimiter(char const *s, char *delim, int idx, int *quote_flags);

#endif