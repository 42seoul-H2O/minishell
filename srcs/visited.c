/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visited.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:02:13 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/13 17:06:25 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_visited	*init_visited(void)
{
	t_visited	*visited;

	visited = malloc(sizeof(t_visited));
	if (!visited)
		ft_exit(12);
	visited->head = malloc(sizeof(t_vnode));
	if (!visited -> head)
		ft_exit(12);
	visited->head->visited_idx = -1;
	visited->head->next = NULL;
	return (visited);
}

int	set_visited(t_visited *visited, int idx)
{
	t_vnode	*vnode;

	vnode = visited->head;
	while (vnode->next)
		vnode = vnode->next;
	vnode->next = malloc(sizeof (t_vnode));
	if (!vnode->next)
		ft_exit(12);
	vnode->next->visited_idx = idx;
	vnode->next->next = NULL;
	return (1);
}

int	is_visited(t_visited *visited, int idx)
{
	t_vnode	*vnode;

	vnode = visited->head;
	while (vnode)
	{
		if (vnode->visited_idx == idx)
			return (1);
		vnode = vnode->next;
	}
	return (0);
}

void	destroy_visited(t_visited *visited)
{
	t_vnode	*vnode;
	t_vnode	*temp;

	vnode = visited->head;
	while (vnode)
	{
		temp = vnode;
		vnode = vnode->next;
		free(temp);
	}
	free(visited);
}
