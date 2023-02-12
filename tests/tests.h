/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:30:47 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/12 16:27:18 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# include <stdarg.h>

enum e_env
{
	NOT_HAVE_ENV,
	HAS_ENV
};

void	test_split(void);
void	test_parser(void);

#endif