/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dollar_to_env2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:09:04 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/06 17:01:05 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "builtin.h"

void	convert_dollar_to_env(t_str *str, char **envp)
{
	while (convert_single_dollar_to_env(str, envp))
		;
}

int	replace_dollar_with_env(t_str *str, t_dollar_sign *dollar)
{
	char	*dest1;
	char	*dest2;
	char	*dest3;

	if (dollar -> first_idx == dollar -> last_idx)
		return (0);
	dest1 = malloc(sizeof (char) * (dollar -> first_idx) + 1);
	if (!dest1)
		builtin_exit(12);
	if (!ft_strlcpy(dest1, str -> s, dollar -> first_idx + 1))
		builtin_exit(12);
	dest2 = ft_strjoin(dest1, dollar -> env_value);
	if (!dest2)
		builtin_exit(12);
	free(dest1);
	dest3 = ft_strjoin(dest2, str -> s + dollar -> last_idx + 1);
	if (!dest3)
		builtin_exit(12);
	free(dest2);
	str -> s = dest3;
	return (1);
}

int	*init_ignore_idx(void)
{
	
}