/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:35:53 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/13 16:38:50 by hyunjuki         ###   ########.fr       */
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

void	builtin_echo(char **input, t_vararr *env)
{
	int	i;

	i = 1;
	i += check_n_option(input[1]);
	while (input[i] != NULL)
	{
		// if (input[i][0] == '$')
		// {
		// 	if (ft_getenv(env, &input[i][1]) == NULL)
		// 	{
		// 		i++;
		// 		continue ;
		// 	}
		// 	printf("%s", ft_getenv(env, &input[i][1]));
		// }
		// else
		printf("%s", input[i]);
		i++;
		if (input[i] != NULL)
			printf(" ");
	}
	if (check_n_option(input[1]) != 1)
		printf("\n");
}
