/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pipe_and_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:23:25 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/17 19:31:31 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_redirection(t_cmdlist *node)
{
	
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
