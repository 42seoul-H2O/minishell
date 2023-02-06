/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:34 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/06 12:58:05 by hyunjuki         ###   ########.fr       */
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
	temp->arr[0] = ft_strdup("Hello");
	temp->arr[1] = ft_strdup("World");
	printf("%s\n", temp->arr[0]);
	printf("%s\n", temp->arr[1]);
	temp->len = 2;
	printf("%d\n", temp->capacity);
	realloc_2x_arr(temp);
	printf("%d\n", temp->capacity);
	printf("%s\n", temp->arr[0]);
	printf("%s\n", temp->arr[1]);
	tt = copy_arr(temp);
	destroy_arr(temp);
	printf("%s %s\n", tt[0], tt[1]);
	free_arr(tt);
	system("leaks minishell");
}