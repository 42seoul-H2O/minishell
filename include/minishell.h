/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:07 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/09 17:55:24 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "constants.h"
# include "prompt.h"
# include "vararr.h"
# include "cmdlist.h"

int		init(t_vararr **env, char **envp);
int		init_env_arr(t_vararr *env, char **envp);
int		*find_quote(char const *s, char *c, int start_idx);
int		get_word_len(char const *s, char *c, int start_idx);
char	**ft_tokenize(char const *s, char *c);

#endif