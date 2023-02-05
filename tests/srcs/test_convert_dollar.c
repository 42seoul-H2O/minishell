/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_convert_dollar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:33:59 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/05 20:49:43 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"

static void	convert_dollar_test(char *s);
static void	init_envp(char **envp);

void	test_convert_dollar(void)
{
	printf("---- Convert_dollar Test Cases ----\n");
	convert_dollar_test("blahblah $");
	printf("---- End of Convert_dollar ----\n\n");
	// blahblah $
	// blahblah $"dff"
	// blahblah$
	// blahblah $.
	// $bkjidf
	// $ dkjidf
	// $
	// $.
	// $,
	// $'' $이후에 바로 
}

static void	convert_dollar_test(char *s)
{
	t_str	str;
	char	**envp;

	init_t_str(&str, s);
	// init_envp(envp);
	printf("---- Test Case: %s, with an empty envp\n", s);
	envp[0] = NULL;
	convert_dollar_to_env(&str, envp);
	printf("---- Output ----\n");
}

static void	init_envp(char **envp)
{
	envp[0] = "SHELL=/bin/bash";
	envp[1] = "PWD=Users/hocsong/Documents/minishell/ms1";
	envp[2] = "LOGNAME=hocsong";
	envp[3] = "LaunchInstanceID=1525446E-700F-4494-A67E-8DD2AF55B79B";
	envp[4] = "HOME=/Users/hocsong";
	envp[5] = NULL;
}
