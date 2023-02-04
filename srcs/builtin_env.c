/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:23:42 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/04 18:29:54 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	builtin_env(char **input, char **env)
{
	int	i;

	if (input[1] == NULL)
	{
		i = 0;
		while (env[i] != NULL)
			printf("%s\n", env[i++]);
	}
}
