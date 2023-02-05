/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:11:02 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/05 13:28:35 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_quote{
	int		is_quoted;
	char	type;
}t_quote;

typedef struct s_str{
	char	*s;
	char	*delimiters;
	char	*included_delimiters;
	int		*token_indices;
	int		*quote_flags;
	int		word_count;
}t_str;

// char	**tokenize(char const *s);
void	init_t_str(t_str *str, char *s);
void	set_token_indices(t_str *str);
void	set_word_count(t_str *str);
int		get_word_len(t_str *str, int start_idx);
int		is_quoted(t_str *str, int idx);
int		is_special_delimiter(t_str *str, int idx);
int		is_delimiter(t_str *str, int idx);

#endif