/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:34 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/06 13:52:34 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init(void)
{
	init_term_setting();
	set_sig_handler();
	return (0);
}

static char	**freeall(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static int	split_len(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


// int	main(int argc, char **argv, char **envp)
// {
// 	char	*line;
// 	char	**splited;

// 	if (init() == -1)
// 		return (-1);
// 	line = NULL;
// 	line = get_line(line);
// 	while (line != NULL)
// 	{
// 		splited = ft_split(line, ' ');
// 		exec_builtins(splited, split_len(splited));
// 		splited = freeall(splited);
// 		line = get_line(line);
// 	}
// 	return (0);
// }

int	main(int argc, char **argv, char **envp)
{
	t_vararr	*temp;
	int			i;
	char		**tt;

	i = 0;
	while (envp[i] != NULL)
		i++;
	temp = make_new_arr(i);
	for (i = 0; envp[i] != NULL; i++)
		append_element(temp, envp[i]);
	for (i = 0; i < temp->len; i++)
		printf("%s\n", get_element(temp, i));
	printf("-----------------------\n");
	append_element(temp, "a=1");
	printf("%s\n", get_element(temp, temp->len - 1));
	printf("-----------------------\n");
	update_element(temp, "a", "2");
	printf("%s\n", get_element(temp, temp->len - 1));
	printf("%s\n", get_element(temp, find_element(temp, "USER")));
	printf("-----------------------\n");
	update_element(temp, "USER", "hocsong");
	for (i = 0; i < temp->len; i++)
		printf("%s\n", get_element(temp, i));
	destroy_arr(temp);
	system("leaks minishell");
}