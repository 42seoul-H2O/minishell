/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_convert_dollar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:33:59 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/06 10:32:20 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"

static void	convert_dollar_test(char *input, int has_envp, \
			char *expected_output);
static char	**init_envp(void);

void	test_convert_dollar(void)
{
	printf("---- Convert_dollar Test Cases ----\n");
	convert_dollar_test("blahblah $", 1, "blahblah $");
	convert_dollar_test("blahblah $", 0, "blahblah $");
	convert_dollar_test("blahblah $\"dff\"", 1, "blahblah ");
	convert_dollar_test("blahblah $\"dff\"", 0, "blahblah ");
	convert_dollar_test("blahblah $\"LOGNAME\"", 1, "blahblah hocsong");
	convert_dollar_test("blahblah $\"LOGNAME\"", 0, "blahblah ");
	convert_dollar_test("blahblah$", 1, "blahblah$");
	convert_dollar_test("blahblah$", 0, "blahblah$");
	convert_dollar_test("blahblah $.", 1, "blahblah $.");
	convert_dollar_test("blahblah $.", 0, "blahblah $.");
	convert_dollar_test("$yadi", 1, "");
	convert_dollar_test("$yadi", 0, "");
	convert_dollar_test("$", 1, "$");
	convert_dollar_test("$.", 1, "$.");
	convert_dollar_test("$,", 1, "$,");
	convert_dollar_test("$\'", 1, "$\'");
	printf("---- End of Convert_dollar ----\n\n");
}

static void	convert_dollar_test(char *input, int has_envp, \
			char *expected_output)
{
	t_str	str;
	char	**envp;

	init_t_str(&str, input);
	envp = init_envp();
	printf("---- Test Case: %s has_envp: %d\n", input, has_envp);
	convert_dollar_to_env(&str, envp);
	printf("---- Output ----\n");
	printf("%s\n", str.s);
	printf("---- Expected Output with envp----\n");
	printf("%s\n", expected_output);
	free(envp);
}

static char	**init_envp(void)
{
	char	**envp;

	envp = malloc(sizeof (char *) * 6);
	envp[0] = "SHELL=/bin/bash";
	envp[1] = "PWD=Users/hocsong/Documents/minishell/ms1";
	envp[2] = "LOGNAME=hocsong";
	envp[3] = "LaunchInstanceID=1525446E-700F-4494-A67E-8DD2AF55B79B";
	envp[4] = "HOME=/Users/hocsong";
	envp[5] = NULL;
	return (envp);
}
