/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_and_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:00:07 by hocsong           #+#    #+#             */
/*   Updated: 2023/01/03 10:13:49 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error_and_exit(char *prefix1, char *prefix2)
{
	char	*err_prefix;

	prefix1 = ft_strjoin(prefix1, ": ");
	err_prefix = ft_strjoin(prefix1, prefix2);
	perror(err_prefix);
	exit(1);
}

void	print_error(char *prefix1, char *prefix2)
{
	char	*err_prefix;

	prefix1 = ft_strjoin(prefix1, ": ");
	err_prefix = ft_strjoin(prefix1, prefix2);
	perror(err_prefix);
}
