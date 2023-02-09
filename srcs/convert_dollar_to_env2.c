/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dollar_to_env2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:09:04 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/09 18:41:33 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "builtin.h"
#include "vararr.h"

//TODO: convert_single_dollar_to_env를 실행할 때 마다 문자열을 malloc하기 때문에
//		leak가 발생할거다. 이거 꼭 잡자.

void	convert_dollar_to_env(t_str *str, char **envp)
{
	int	*visited;

	visited = init_visited(ft_strlen(str -> s));
	convert_single_dollar_to_env(str, envp, visited);
	while (convert_single_dollar_to_env(str, envp, visited))
		;
	free(visited);
}

int	replace_dollar_with_env(t_str *str, t_dollar_sign *dollar, \
	int *visited)
{
	char	*dest1;
	char	*dest2;
	char	*dest3;

	if (dollar -> first_idx == dollar -> last_idx)
	{
		visited[dollar -> first_idx] = 1;
		return (0);
	}
	dest1 = malloc(sizeof (char) * (dollar -> first_idx) + 1);
	if (!dest1)
		builtin_exit(12);
	ft_strlcpy(dest1, str -> s, dollar -> first_idx + 1);
	dest2 = ft_strjoin(dest1, dollar -> env_value);
	if (!dest2)
		builtin_exit(12);
	free(dest1);
	dest3 = ft_strjoin(dest2, str -> s + dollar -> last_idx + 1);
	if (!dest3)
		builtin_exit(12);
	free(dest2);
	free(str -> s);
	str -> s = dest3;
	return (1);
}

int	*init_visited(int size)
{
	int	i;
	int	*visited;

	i = 0;
	visited = malloc(sizeof (int) * size);
	if (!visited)
		builtin_exit(12);
	while (i < size)
	{
		visited[i] = 0;
		i++;
	}
	return (visited);
}
