/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:29:34 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/21 16:05:50 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include "../lib/libft/libft.h"
# include "vararr.h"
# include "cmdlist.h"
# include "constants.h"

int		exec_single_builtin(t_cmdlist *exec, t_vararr *env);
int		exec_builtins(t_cmdlist *exec, t_vararr *env);
void	ft_exit(int errnum);
void	builtin_exit(t_cmdlist	*node);
void	builtin_pwd(void);
void	builtin_cd(t_cmdlist *node, t_vararr *env);
void	builtin_export(t_cmdlist *node, t_vararr *env);
int		builtin_export_check_args(char *argument, t_vararr *env);
void	builtin_unset(t_cmdlist *node, t_vararr *env);
void	builtin_env(t_cmdlist *node, t_vararr *env);
void	builtin_echo(t_cmdlist *node);

void	swap_element(char **a, char **b);

#endif