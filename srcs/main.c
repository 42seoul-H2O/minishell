/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:34 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/04 13:59:19 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init(void)
{
	init_term_setting();
	set_sig_handler();
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	if (init() == -1)
		return (-1);
	line = NULL;
	line = get_line(line);
	while (line != NULL)
	{
		exec_builtins(line);
		line = get_line(line);
	}
	return (0);
}
