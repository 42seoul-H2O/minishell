/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:38:43 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/19 14:58:24 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "../lib/libft/libft.h"
# include "builtin.h"

void	set_sig_handler(void);
void	set_sig_ignore(void);
void	set_sig_default(void);
void	interupt_handler(int signum);
char	*get_line(char *line);

#endif