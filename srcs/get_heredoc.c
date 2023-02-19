/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:35:37 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/19 16:07:30 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_heredoc(t_cmdlist *node)
{
	t_cmdlist	*curr;
	char		*temp;
	int			i;

	curr = node;
	while (curr)
	{
		i = 0;
		while (i < curr->args->words_count)
		{
			if (curr->args->token_types[i] == HEREDOC)
			{
				curr->args->token_types[i] = REDIR_IN;
				temp = get_heredoc(curr->args->words[i + 1]);
				free(curr->args->words[i + 1]);
				curr->args->words[i + 1] = temp;
				i++;
			}
			i++;
		}
		curr = curr->next;
	}
}

char	*get_heredoc(char *eof)
{
	static unsigned char	file_i;
	char					*line;
	char					*filename;
	int						fd;
	pid_t					pid;

	line = ft_itoa((int)file_i);
	filename = ft_strjoin(".my_heredoc_temp_", line);
	free(line);
	pid = fork();
	if (pid == 0)
	{
		set_sig_default();
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
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
		exit(0);
	}
	wait(NULL);
	set_sig_handler();
	return (filename);
}

void	destroy_heredoc(void)
{
	unsigned char	i;
	char			*temp;
	char			*idx;

	i = 0;
	while (i <= 255)
	{
		idx = ft_itoa(i);
		temp = ft_strjoin(".my_heredoc_temp_", idx);
		free(idx);
		if (access(temp, F_OK) != -1)
			if (unlink(temp) == -1)
				ft_putstr_fd("h2osh: failed to delete heredoc file\n", 2);
		free(temp);
		i++;
	}
}
