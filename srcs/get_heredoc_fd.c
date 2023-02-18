/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:35:37 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/18 15:38:29 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "prompt.h"

int	get_heredoc_fd(char *eof)
{
	char	*line;
	int		fd;

	fd = open("heredoc_temp", O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (!fd)
		ft_exit(1);
	line = readline("> ");
	if (write(fd, line, ft_strlen(line)) == -1)
		exit(1);
	while (ft_strncmp(line, eof, ft_strlen(eof) + 1))
	{
		free(line);
		line = readline("> ");
		if (write(fd, line, ft_strlen(line)) == -1)
			exit(1);
	}
	free(line);
	return (fd);
}
