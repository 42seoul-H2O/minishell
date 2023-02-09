/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:47:36 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/09 17:51:46 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMDLIST_H
# define CMDLIST_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../lib/libft/libft.h"
# include "vararr.h"

typedef struct s_list
{
	char		*cmd;
	t_vararr	*args;
	int			cmd_type;
	int			pipe[2];
	t_list		*prev;
	t_list		*next;
}				t_list;

t_list	*make_new_node(t_list *prev);
void	set_cmd(t_list *node, char *str);
void	destory_node(t_list *node);
void	destory_list(t_list *head);
t_list	*list_reset_loc(t_list *curr);


#endif