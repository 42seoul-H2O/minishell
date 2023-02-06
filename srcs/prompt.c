/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:20:02 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/06 14:36:53 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h" 

void	set_sig_handler(void)
{
	signal(SIGINT, interupt_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	interupt_handler(int signum)
{
	if (signum != SIGINT)
		return ;
	write(STDOUT_FILENO, "\n", 1);
	if (rl_on_new_line() == -1)
		exit(-1);
	rl_replace_line("", 1);
	rl_redisplay();
}

char	*get_line(char *line)
{
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	line = readline("h2osh$ ");
	if (line == NULL)
		builtin_exit(0);
	add_history(line);
	return (line);
}
