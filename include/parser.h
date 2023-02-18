/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:11:02 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/18 19:10:01 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "vararr.h"
# include <fcntl.h>

typedef struct s_quote{
	int		is_quoted;
	char	type;
}t_quote;

typedef struct s_dollar_sign{
	int		first_idx;
	int		last_idx;
	char	*env_value;
}t_dollar_sign;

typedef struct s_vnode{
	int				visited_idx;
	struct s_vnode	*next;
}t_vnode;

typedef struct s_visited{
	t_vnode	*head;
}t_visited;

typedef struct s_str{
	char	*s;
	char	*delimiters;
	char	*included_delimiters;
	int		*token_indices;
	int		*quote_flags;
	char	**words;
	int		word_count;
	int		merge_count;
}t_str;

typedef struct s_parsed{
	int		*token_types; // 실행부에서 free 필요
	char	**words; // 실행부에서 free 필요.
	int		words_count;
}t_parsed;

typedef struct s_cmd_list
{
	char		*cmd;
	t_vararr	*args;
	int			cmd_type;
	int			pipe[2];
	t_list		*next;
	t_list		*prev;
}t_cmd_list;

enum e_cmd_type
{
	EXECUTABLE,
	CD,
	ECHO,
	ENV,
	EXIT,
	EXPORT,
	PWD,
	UNSET,
};

t_parsed	parse(char *input, t_vararr *env);
void		init_t_str(t_str *str, char *s);
void		destroy_t_str(t_str *str);
char		**my_split(t_str *str);
void		set_token_indices(t_str *str);
void		set_word_count(t_str *str);
int			get_word_len(t_str *str, int start_idx);
int			is_quoted(t_str *str, int idx);
int			is_special_delimiter(t_str *str, int idx);
int			is_delimiter(t_str *str, int idx);
void		destroy_parsed(t_parsed *parsed);

void		replace_dollar_with_env(t_str *str, int word_i, \
			t_dollar_sign *dollar, t_visited *visited);
void		convert_dollar_to_env(t_str *str, t_vararr *env);
int			convert_single_dollar_to_env(t_str *str, int word_i, \
			t_vararr *env, t_visited *visited);
int			set_visited(t_visited *visited, int idx);
t_visited	*init_visited(void);
int			is_visited(t_visited *visited, int idx);
void		destroy_visited(t_visited *visited);
int			is_unallowed_char(char *word, int char_idx);

void		remove_quotes(t_str *str);

void		merge_redir_tokens(t_str *str);
int			*get_token_types(t_str *str);
int			get_token_type(char **words, int idx);
int			get_optype(char *word);
int			is_cmd(char **words, int idx);
int			is_redir_word(char **words, int idx);

void		catch_syntax_err(t_parsed *parsed);
void		catch_unmatching_quotes(t_parsed *parsed);

#endif