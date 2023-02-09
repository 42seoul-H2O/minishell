/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_convert_dollar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:33:59 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/09 15:30:11 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"

static void	convert_dollar_test(char *input, int has_envp, \
			char *expected_output);
static char	**init_envp(void);

void	test_convert_dollar(void)
{
	char	*name;

	name = malloc(sizeof (char) * 100);
	if (!name)
		exit (1);
	printf("---- Convert_dollar Test Cases ----\n");
	convert_dollar_test("blahblah $", 1, "blahblah $");
	convert_dollar_test("blahblah $^", 1, "blahblah $^");
	convert_dollar_test("blahblah $\'\'", 1, "blahblah $\'\'");
	convert_dollar_test("blahblah $\'PATH\'", 1, "blahblah $\'PATH\'");
	convert_dollar_test("blahblah $\"PATH\"", 1, "blahblah $PATH");
	convert_dollar_test("blahblah \"$\"PATH", 1, "blahblah $PATH");
	convert_dollar_test("blahblah \"$'PATH\"", 1, "blahblah $\'PATH");
	convert_dollar_test("blahblah \'$\"PATH\'", 1, "blahblah $\"PATH\"");
	convert_dollar_test("blahblah \'\"$PATH\"\'", 1, "blahblah \"$PATH\"");
	convert_dollar_test("$SHELL$LOGNAME", 1, "/bin/bashhocsong");
	convert_dollar_test("blahblah $", 0, "blahblah $");
	convert_dollar_test("blahblah $\"dff\"", 1, "blahblah ");
	convert_dollar_test("blahblah $\"dff\"", 0, "blahblah ");
	convert_dollar_test("blahblah $\"LOGNAME\"", 1, "blahblah hocsong");
	convert_dollar_test("blahblah $\"LOGNAME\"", 0, "blahblah ");
	convert_dollar_test("blahblah$", 1, "blahblah$");
	convert_dollar_test("blahblah$", 0, "blahblah$");
	convert_dollar_test("blahblah $.", 1, "blahblah $.");
	convert_dollar_test("blahblah $.", 0, "blahblah $.");
	convert_dollar_test("$HOME is defined!", 1, "/Users/hocsong is defined!");
	convert_dollar_test("$HOMEI is undefined!", 1, " is undefined!");
	convert_dollar_test("$yadi", 1, "");
	convert_dollar_test("$yadi", 0, "");
	convert_dollar_test("$", 1, "$");
	convert_dollar_test("$.", 1, "$.");
	convert_dollar_test("$,", 1, "$,");
	convert_dollar_test("$\'", 1, "$\'");
	convert_dollar_test("abc$SHELL\'ab\'", 1, "abc/bin/bash\'ab\'");
	convert_dollar_test("abc$SHELL\'ab\'", 0, "abc\'ab\'");
	//Test cases with more than one $
	convert_dollar_test("blahblah $$", 1, "blahblah $$");
	convert_dollar_test("blahblah $$$", 1, "blahblah $$$");
	convert_dollar_test("blahblah $ $", 1, "blahblah $ $");
	convert_dollar_test("blahblah $ $", 0, "blahblah $ $");
	convert_dollar_test("blahblah $\"dff\" $", 1, "blahblah $");
	convert_dollar_test("blahblah $\"dff\" $", 0, "blahblah $");
	printf("---- End of Convert_dollar ----\n\n");
}

static void	convert_dollar_test(char *input, int has_envp, \
			char *expected_output)
{
	t_str	str;
	char	**envp;

	str.s = malloc(sizeof (char) * 100);
	if (!str.s)
		exit(1);
	ft_strlcpy(str.s, input, 100);
	init_t_str(&str, input);
	envp = init_envp();
	printf("---- Test Case: %s ----\n", input);
	printf("---- has_envp: %d ----\n", has_envp);
	convert_dollar_to_env(&str, envp);
	printf("---- Output ----\n");
	printf("%s\n", str.s);
	printf("---- Expected Output ----\n");
	printf("%s\n\n", expected_output);
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
