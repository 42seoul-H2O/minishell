/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:11:02 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/06 14:00:35 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_quote{
	int		is_quoted;
	char	type;
}t_quote;

typedef struct s_dollar_sign{
	int		first_idx;
	int		last_idx;
	char	*env_value;
}t_dollar_sign;

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
char	**my_split(t_str *str);
void	set_token_indices(t_str *str);
void	set_word_count(t_str *str);
int		get_word_len(t_str *str, int start_idx);
int		is_quoted(t_str *str, int idx);
int		is_special_delimiter(t_str *str, int idx);
int		is_delimiter(t_str *str, int idx);
char	*my_getenv(char **envp, char *name);
int		replace_dollar_with_env(t_str *str, t_dollar_sign *dollar);
void	convert_dollar_to_env(t_str *str, char **envp);
int		convert_single_dollar_to_env(t_str *str, char **envp);

#endif