/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:08:54 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/18 15:52:25 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "tests.h"

int	g_exit_code = 0;

void	check_leak(void)
{
	system("leaks test");
}

int	main(void)
{
	atexit(check_leak);
	// test_split();
	test_parser();
}
