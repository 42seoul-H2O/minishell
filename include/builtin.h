/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:29:34 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/04 15:23:04 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../lib/libft/libft.h"

void	exec_builtins(char *line);
void	builtin_exit(int errnum);
void	builtin_pwd(void);

#endif