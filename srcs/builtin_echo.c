/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:35:53 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/09 18:44:52 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	check_n_option(char *input)
{
	int	i;

	if (input == NULL)
		return (0);
	if (input[0] != '-')
		return (0);
	i = 1;
	while (input[i] != '\0')
	{
		if (input[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	builtin_echo(t_list *node, t_vararr *env)
{
	int		i;
	char	*temp;

	i = 0;
	i += check_n_option(get_element(node->args, 0));
	while (i < node->args->len)
	{
		temp = get_element(node->args, i);
		if (temp[0] == '$') // TODO : 달러 사인 파싱 부분 삭제
		{
			if (ft_getenv(env, &temp[1]) == NULL)
			{
				i++;
				continue ;
			}
			printf("%s", ft_getenv(env, &temp[1]));
		}
		else
			printf("%s", temp);
		i++;
		if (temp != NULL)
			printf(" ");
	}
	if (check_n_option(get_element(node->args, 0)) != 1)
		printf("\n");
}
