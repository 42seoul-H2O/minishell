/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:11:02 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/12 14:01:40 by hocsong          ###   ########seoul.kr  */
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

typedef struct s_str{
	char	*s;
	char	*delimiters;
	char	*included_delimiters;
	int		*token_indices;
	int		*quote_flags;
	char	**words;
	int		word_count;
}t_str;

typedef struct s_cmd_list
{
	char		*cmd;
	t_vararr	*args;
	int			cmd_type;
	int			pipe[2];
	int			input_fd;
	int			output_fd;
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

t_str	parse(char *input, t_vararr *env);
void	init_t_str(t_str *str, char *s);
char	**my_split(t_str *str);
void	set_token_indices(t_str *str);
void	set_word_count(t_str *str);
int		get_word_len(t_str *str, int start_idx);
int		is_quoted(t_str *str, int idx);
int		is_special_delimiter(t_str *str, int idx);
int		is_delimiter(t_str *str, int idx);

int		replace_dollar_with_env(t_str *str, int word_i, t_dollar_sign *dollar, \
		int *visited);
void	convert_dollar_to_env(t_str *str, t_vararr *env);
int		convert_single_dollar_to_env(t_str *str, int word_i, \
		t_vararr *env, int *visited);
int		*init_visited(int size);

void	remove_quotes(t_str *str);

#endif