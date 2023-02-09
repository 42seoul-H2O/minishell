/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:29:34 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/09 18:39:17 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../lib/libft/libft.h"
# include "vararr.h"
# include "cmdlist.h"
# include "constants.h"

int		exec_builtins(t_list *exec, t_vararr *env);
void	ft_exit(int errnum);
void	builtin_exit(t_list	*node);
void	builtin_pwd(void);
void	builtin_cd(t_list *node);
void	builtin_export(t_list *node, t_vararr *env);
void	builtin_export_check_args(char *argument, t_vararr *env);
void	builtin_unset(t_list *node, t_vararr *env);
void	builtin_env(char **input, t_vararr *env);
void	builtin_echo(char **input, t_vararr *env);

void	swap_element(char **a, char **b);

#endif