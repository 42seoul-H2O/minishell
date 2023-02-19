/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:35:37 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/19 12:25:45 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "prompt.h"

int	get_heredoc_fd(char *eof)
{
	char	*line;
	int		fd;

	fd = open(".my_heredoc_temp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!fd)
		exit(1);
	line = readline("> ");
	while (ft_strncmp(line, eof, ft_strlen(eof) + 1))
	{
		ft_putendl_fd(line, fd);
		free(line);
		line = readline("> ");
	}
	free(line);
	close(fd);
	fd = open(".my_heredoc_temp", O_RDONLY, 0644);
	return (fd);
}
