/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:11:02 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/17 21:38:42 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "vararr.h"
# include "constants.h"
# include "../lib/libft/libft.h"
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
}t_str;

typedef struct s_parsed
{
	int		word_count;
	int		*token_types;
	char	**words;
}t_parsed;

t_parsed	*parse(char *input, t_vararr *env);
void		init_t_str(t_str *str, char *s);
void		destroy_t_str(t_str *str);
char		**my_split(t_str *str);
void		set_token_indices(t_str *str);
void		set_word_count(t_str *str);
int			get_word_len(t_str *str, int start_idx);
int			is_quoted(t_str *str, int idx);
int			is_special_delimiter(t_str *str, int idx);
int			is_delimiter(t_str *str, int idx);

int			replace_dollar_with_env(t_str *str, int word_i, \
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

#endif