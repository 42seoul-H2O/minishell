/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:34 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/03 16:57:37 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init(void)
{
	init_term_setting();
	signal(SIGINT, interupt_handler);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	if (init() == -1)
		return (-1);
	line = get_line();
	while (line != NULL)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
		line = get_line();
	}
	return (0);
}
