/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:55:09 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/09 18:07:35 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmdlist.h"

t_list	*make_new_node(t_list *prev)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->args = make_new_arr(5);
	if (!(result->args))
	{
		free(result);
		return (NULL);
	}
	result->cmd = NULL;
	result->cmd_type = -1;
	result->next = NULL;
	if (prev)
		result->prev = prev;
	else
		result->prev = NULL;
	return (result);
}

int	set_cmd(t_list *node, char *str)
{
	char	*temp;

	if (!node || !str)
		return (-1);
	temp = ft_strdup(str);
	if (!temp)
		return (-1);
	node->cmd = temp;
	return (1);
}

void	destory_node(t_list *node)
{
	if (node->args)
		destroy_arr(node->args);
	if (node->cmd)
		free(node->cmd);
	close(node->pipe[0]);
	close(node->pipe[1]);
	free(node);
	node = NULL;
}

void	destory_list(t_list *head)
{
	t_list	*curr;
	t_list	*temp;

	curr = head;
	while (!curr)
	{
		temp = curr->next;
		destory_node(curr);
		curr = temp;
	}
}

t_list	*list_reset_loc(t_list *curr)
{
	t_list	*temp;

	temp = curr;
	while (!(temp->prev))
		temp = temp->prev;
	return (temp);
}
