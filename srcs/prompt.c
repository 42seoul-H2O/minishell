/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:20:02 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/03 17:08:14 by hyunjuki         ###   ########.fr       */
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

void	init_term_setting(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

char	*get_line(void)
{
	char	*line;

	line = readline("h2osh$ ");
	if (line == NULL)
	{
		printf("\033[1A");
		printf("\033[7C");
		printf("exit\n");
		exit(0);
	}
	if (ft_strncmp(line, "quit", sizeof(line)) == 0)
	{
		free(line);
		return (NULL);
	}
	add_history(line);
	return (line);
}
