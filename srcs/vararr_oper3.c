/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vararr_oper3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:37:48 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/06 14:00:35 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vararr.h"

char	*ft_getenv(t_vararr *env, char *key)
{
	int		i;
	char	*temp;

	i = find_element(env, key);
	if (i == -1)
		return (NULL);
	temp = get_element(env, i);
	temp = ft_strnstr(temp, "=", ft_strlen(temp));
	return (++temp);
}

char	*ft_setenv(t_vararr *env, char *key, char *value, int overwrite)
{

}

int	ft_unsetenv(t_vararr *env, char *key)
{

}

void	print_all_string(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		printf("%s\n", arr[i++]);
}
