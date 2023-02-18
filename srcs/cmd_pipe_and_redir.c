/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pipe_and_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:23:25 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/18 11:21:13 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_redirection(t_cmdlist *node)
{
	int	i;
	int	fd;

	i = 0;
	while (i < node->args->word_count)
	{
		if (node->args->token_types[i] == REDIR_IN || \
			node->args->token_types[i] == REDIR_OUT || \
			node->args->token_types[i] == APPEND)
		{
			if (!open_redir_and_set_fd(node, i, node->args->token_types[i]))
				return (i);
			parsed_delete_idx(node->args, i);
			parsed_delete_idx(node->args, i);
		}
		else
			i++;
	}
	return (0);
}

int	open_redir_and_set_fd(t_cmdlist *node, int idx, int type)
{
	int	fd;

	if (type == REDIR_IN)
		fd = open(node->args->words[idx + 1], O_RDONLY, 0644);
	else if (type == REDIR_OUT)
		fd = open(node->args->words[idx + 1], O_WRONLY | O_CREAT, 0644);
	else if (type == APPEND)
		fd = open(node->args->words[idx + 1], O_WRONLY | O_APPEND | O_CREAT, \
			0644);
	if (fd == -1)
		return (0);
	if (type == REDIR_IN)
		dup2(fd, STDIN_FILENO);
	else
		dup2(fd, STDOUT_FILENO);
	close(fd);
	return (1);
}

void	set_pipe_fd(t_cmdlist *node)
{
	if (node->prev != NULL)
	{
		dup2(node->prev->pipe[0], STDIN_FILENO);
		close(node->prev->pipe[0]);
		close(node->prev->pipe[1]);
	}
	if (node->next != NULL)
	{
		dup2(node->pipe[1], STDOUT_FILENO);
		close(node->pipe[1]);
		close(node->pipe[0]);
	}
}

void	close_prev_pipe(t_cmdlist *node)
{
	if (node->prev && node->prev->prev)
	{
		close(node->prev->prev->pipe[0]);
		close(node->prev->prev->pipe[1]);
		node->prev->prev->pipe[0] = 0;
		node->prev->prev->pipe[1] = 1;
	}
}
