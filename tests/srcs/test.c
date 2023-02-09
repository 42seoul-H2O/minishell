/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:08:54 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/06 19:53:30 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "tests.h"

void	check_leak(void)
{
	system("leaks test");
}

int	main(void)
{
	atexit(check_leak);
	// test_split();
	test_convert_dollar();
}
