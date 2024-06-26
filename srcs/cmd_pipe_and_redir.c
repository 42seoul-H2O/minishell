/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pipe_and_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:23:25 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/21 15:17:35 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_redirection(t_cmdlist *node)
{
	int	i;
	int	fd;

	i = 0;
	while (i < node->args->words_count)
	{
		if (node->args->token_types[i] == REDIR_IN || \
			node->args->token_types[i] == REDIR_OUT || \
			node->args->token_types[i] == APPEND)
		{
			if (!open_redir_and_set_fd(node, i, node->args->token_types[i]))
				return (i + 1);
			parsed_delete_idx(node->args, i);
			parsed_delete_idx(node->args, i);
		}
		else
			i++;
	}
	return (0);
}

int	open_redir_and_set_fd(t_cmdlist *n, int idx, int type)
{
	int	fd;

	if (type == REDIR_IN)
		fd = open(n->args->words[idx + 1], O_RDONLY, 0644);
	else if (type == REDIR_OUT)
		fd = open(n->args->words[idx + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == APPEND)
		fd = open(n->args->words[idx + 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		return (0);
	if (type == REDIR_IN || type == HEREDOC)
	{
		if (dup2(fd, STDIN_FILENO) == -1)
			exit(11);
	}
	else
	{
		if (dup2(fd, STDOUT_FILENO) == -1)
			exit(11);
	}
	close(fd);
	return (1);
}

void	set_pipe_fd(t_cmdlist *node)
{
	t_cmdlist	*curr;

	curr = list_reset_loc(node);
	if (node->prev != NULL)
	{
		if (dup2(node->prev->pipe[0], STDIN_FILENO) == -1)
			exit(11);
	}
	if (node->next != NULL)
	{
		if (dup2(node->pipe[1], STDOUT_FILENO) == -1)
			exit(11);
	}
	while (curr)
	{
		if (curr->pipe[0] != -1)
			close(curr->pipe[0]);
		if (curr->pipe[1] != -1)
			close(curr->pipe[1]);
		curr = curr->next;
	}
}
