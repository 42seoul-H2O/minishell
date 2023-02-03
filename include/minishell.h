/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:07 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/03 19:59:41 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>

# define NO_QUOTE -1

# define SWITCH_OFF 0
# define SWITCH_ON 1

int     *find_quote(char const *s, char *c, int start_idx);
int     get_word_len(char const *s, char *c, int start_idx);
char    **ft_split(char const *s, char *c);

#endif