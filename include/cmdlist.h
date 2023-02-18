/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:47:36 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/18 13:45:59 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMDLIST_H
# define CMDLIST_H

# include <stdlib.h>
# include <unistd.h>
# include "../lib/libft/libft.h"
# include "vararr.h"
# include "parser.h"

typedef struct s_cmdlist
{
	char				*cmd;
	t_parsed			*args;
	int					cmd_type;
	int					pipe[2];
	struct s_cmdlist	*prev;
	struct s_cmdlist	*next;
}				t_cmdlist;

t_cmdlist	*make_new_node(t_cmdlist *prev);
int			set_cmd(t_cmdlist *node, char *str);
void		destroy_node(t_cmdlist *node);
void		destroy_list(t_cmdlist *head);
t_cmdlist	*list_reset_loc(t_cmdlist *curr);

#endif