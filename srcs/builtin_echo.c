/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:35:53 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/04 18:42:45 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	builtin_echo(char **input, char **env)
{
	int	i;

	i = 1;
	while (input[i] != NULL)
	{
		if (input[i][0] == '$')
			printf("%s ", input[i]); //환경 변수가 존재하는지 체크하고, 없으면 x, 있으면 출력하는 함수로 변경
		else
			printf("%s ", input[i]);
		i++;
	}
	printf("\n");
}
