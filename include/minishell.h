/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:07 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/18 18:16:27 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "constants.h"
# include "prompt.h"
# include "vararr.h"
# include "cmdlist.h"
# include "parser.h"
# include <string.h>

extern int	g_exit_code;

int			init(t_vararr **env, char **envp);
int			init_env_arr(t_vararr *env, char **envp);

t_cmdlist	*list_maker(t_parsed *input, t_vararr *env, int *last_pipe);
t_parsed	*subparsed(t_parsed *input, int start, int end);
void		make_prompt(t_vararr *env);
void		prt_syntax_error(void);
void		parsed_delete_idx(t_parsed *p, int idx);
void		destroy_parsed(t_parsed *p);

void		execution(t_cmdlist *node, t_vararr *env);
void		break_pipe_and_wait_child(t_cmdlist *node, pid_t last_child);
void		exec_child(t_cmdlist *node, t_vararr *env);
void		puterr_prompt(char *err);

int			set_redirection(t_cmdlist *node);
void		set_pipe_fd(t_cmdlist *node);
void		close_prev_pipe(t_cmdlist *node);
int			open_redir_and_set_fd(t_cmdlist *node, int idx, int type);

int			is_builtin(t_cmdlist *node);
char		*check_default_path(char *target, char *path);
char		*is_executable(t_cmdlist *node, t_vararr *env);
void		check_cmd_type(t_cmdlist *node, t_vararr *env);

#endif