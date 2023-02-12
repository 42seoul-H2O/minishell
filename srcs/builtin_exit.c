/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:29:08 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/12 12:13:31 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	is_all_digit(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit((int)s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	builtin_exit(t_cmdlist *node)
{
	if (node->args->len > 2)
	{
		printf("exit\nh2osh: exit: too many arguments\n");
		return (1);
	}
	return (-1);
}

int	ft_exit(char *line, t_vararr *input, t_vararr *env, t_cmdlist *lst)
{
	int	errnum;

	printf("%s\n", "exit");
	errnum = 0;
	if (is_all_digit(get_element(lst->args, 1)))
		errnum = ft_atoi(get_element(lst->args, 1));
	else if (lst->args->len == 2)
	{
		printf("exit\nh2osh: exit: %s: numeric argument required\n",
			get_element(lst->args, 1));
		errnum = 2;
	}
	heap_free(line, input, env, lst);
	return (errnum);
}

void	heap_free(char *line, t_vararr *input, t_vararr *env, t_cmdlist *lst)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	if (input)
		destroy_arr(input);
	if (env)
		destroy_arr(env);
	if (lst)
		destroy_list(list_reset_loc(lst));
}
