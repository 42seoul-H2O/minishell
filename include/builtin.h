/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:29:34 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/04 18:36:38 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../lib/libft/libft.h"

void	exec_builtins(char **input, int len);
void	check_exit_code(char **input, int len);
void	builtin_exit(int errnum);
void	builtin_pwd(void);
void	builtin_cd(char *path);
void	builtin_export(char **input, char **env);
void	builtin_env(char **input, char **env);
void	builtin_echo(char **input, char **env);

#endif