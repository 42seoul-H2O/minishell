/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:05:47 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/18 15:26:16 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "minishell.h"

static void	backup_stdio(int std[2])
{
	std[0] = dup(STDIN_FILENO);
	if (std[0] == -1)
		exit(11);
	std[1] = dup(STDOUT_FILENO);
	if (std[1] == -1)
		exit(11);
}

static void	close_backup(int std[2])
{
	if (dup2(std[0], STDIN_FILENO) == -1)
		exit(11);
	if (dup2(std[1], STDOUT_FILENO) == -1)
		exit(11);
	close(std[0]);
	close(std[1]);
}

int	exec_single_builtin(t_cmdlist *exec, t_vararr *env)
{
	int	temp;
	int	std_backup[2];

	if (exec->next == NULL && exec->prev == NULL \
		&& exec->cmd_type > EXECUTABLE)
	{
		backup_stdio(std_backup);
		temp = set_redirection(exec);
		if (temp != 0)
		{
			ft_putstr_fd("h2osh : ", 2);
			ft_putstr_fd(exec->args->words[temp + 1], 2);
			ft_putstr_fd(": ", 2);
			perror(NULL);
			g_exit_code = 1;
			close_backup(std_backup);
		}
		exec_builtins(exec, env);
		close_backup(std_backup);
		return (1);
	}
	return (0);
}

int	exec_builtins(t_cmdlist *exec, t_vararr *env)
{
	if (exec->cmd_type == EXIT)
		builtin_exit(exec);
	else if (exec->cmd_type == PWD)
		builtin_pwd();
	else if (exec->cmd_type == CD)
		builtin_cd(exec);
	else if (exec->cmd_type == EXPORT)
		builtin_export(exec, env);
	else if (exec->cmd_type == UNSET)
		builtin_unset(exec, env);
	else if (exec->cmd_type == ECHO)
		builtin_echo(exec);
	else if (exec->cmd_type == ENV)
		builtin_env(exec, env);
	else
		return (0);
	return (1);
}
