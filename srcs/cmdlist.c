/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:55:09 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/21 00:36:33 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmdlist.h"
#include "minishell.h"

t_cmdlist	*make_new_node(t_cmdlist *prev)
{
	t_cmdlist	*result;

	result = (t_cmdlist *)malloc(sizeof(t_cmdlist));
	if (!result)
		return (NULL);
	result->args = NULL;
	result->cmd = NULL;
	result->cmd_type = -1;
	result->next = NULL;
	result->pipe[0] = -1;
	result->pipe[1] = -1;
	if (prev)
	{
		result->prev = prev;
		prev->next = result;
	}
	else
		result->prev = NULL;
	return (result);
}

int	set_cmd(t_cmdlist *node, char *str)
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

void	destroy_node(t_cmdlist *node)
{
	destroy_parsed(node->args);
	if (node->cmd != NULL)
		free(node->cmd);
	if (node->pipe[0] != -1)
		close(node->pipe[0]);
	if (node->pipe[1] != -1)
		close(node->pipe[1]);
	free(node);
	node = NULL;
}

void	destroy_list(t_cmdlist *head)
{
	t_cmdlist	*curr;
	t_cmdlist	*temp;

	curr = head;
	while (curr != NULL)
	{
		temp = curr->next;
		destroy_node(curr);
		curr = temp;
	}
}

t_cmdlist	*list_reset_loc(t_cmdlist *curr)
{
	t_cmdlist	*temp;

	temp = curr;
	while (temp->prev != NULL)
		temp = temp->prev;
	return (temp);
}
