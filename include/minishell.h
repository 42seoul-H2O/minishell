/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:07 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/13 16:59:27 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "constants.h"
# include "prompt.h"
# include "vararr.h"
# include "cmdlist.h"
# include "parser.h"

int			init(t_vararr **env, char **envp);
int			init_env_arr(t_vararr *env, char **envp);

int			is_builtin(t_cmdlist *node);
char		*check_default_path(char *target, char *path);
char		*is_executable(t_cmdlist *node, t_vararr *env);
void		check_cmd_type(t_cmdlist *node, t_vararr *env);
void		copy_vararr(t_vararr *dst, t_vararr *src);
t_cmdlist	*list_maker(t_vararr *input, t_vararr *env);
t_vararr	*parse_input(char *s, char c);

#endif