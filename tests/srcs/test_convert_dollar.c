/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_convert_dollar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:33:59 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/10 15:15:38 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"
#include "vararr.h"
#include "builtin.h"

static void		convert_dollar_test(char *input, int has_env, \
				char *expected_output);
static t_vararr	*init_env(int has_env);

void	test_convert_dollar(void)
{
	printf("---- Convert_dollar Test Cases ----\n");
	convert_dollar_test("blahblah $", 1, "blahblah $");
	convert_dollar_test("blahblah $^", 1, "blahblah $^");
	convert_dollar_test("blahblah $\'\'", 1, "blahblah $\'\'");
	convert_dollar_test("blahblah $\'PATH\'", 1, "blahblah $\'PATH\'");
	convert_dollar_test("blahblah $\"PATH\"", 1, "blahblah $\"PATH\"");
	convert_dollar_test("blahblah \"$\"PATH", 1, "blahblah \"$\"PATH");
	convert_dollar_test("blahblah \"$\'PATH\"", 1, "blahblah \"$\'PATH\"");
	convert_dollar_test("blahblah \'$\"PATH\'", 1, "blahblah \'$\"PATH\'");
	convert_dollar_test("blahblah \'\"$PATH\"\'", 1, "blahblah \'\"$PATH\"\'");
	convert_dollar_test("$SHELL$LOGNAME", 1, "/bin/bashhocsong");
	convert_dollar_test("blahblah $", 0, "blahblah $");
	convert_dollar_test("blahblah $\"dff\"", 1, "blahblah $\"dff\"");
	convert_dollar_test("blahblah $\"dff\"", 0, "blahblah $\"dff\"");
	convert_dollar_test("blahblah $\"LOGNAME\"", 1, "blahblah $\"hocsong\"");
	convert_dollar_test("blahblah $\"LOGNAME\"", 0, "blahblah $\"LOGNAME\"");
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
	convert_dollar_test("abc$ABC^yap ", 1, "abc^yap ");
	//Test cases with more than one $
	convert_dollar_test("blahblah $$", 1, "blahblah $$");
	convert_dollar_test("blahblah $$$", 1, "blahblah $$$");
	convert_dollar_test("blahblah $ $", 1, "blahblah $ $");
	convert_dollar_test("blahblah $ $", 0, "blahblah $ $");
	convert_dollar_test("blahblah $\"dff\" $", 1, "blahblah $\"dff\" $");
	convert_dollar_test("blahblah $\"dff\" $", 0, "blahblah $\"dff\" $");
	printf("---- End of Convert_dollar ----\n\n");
}

static void	convert_dollar_test(char *input, int has_env, \
			char *expected_output)
{
	t_str		str;
	t_vararr	*env;

	str.s = malloc(sizeof (char) * 100);
	if (!str.s)
		exit(1);
	ft_strlcpy(str.s, input, 100);
	init_t_str(&str, str.s);
	env = init_env(has_env);
	printf("---- Test Case: %s ----\n", input);
	printf("---- has_envp: %d ----\n", has_env);
	convert_dollar_to_env(&str, env);
	printf("---- Output ----\n");
	printf("%s\n", str.s);
	printf("---- Expected Output ----\n");
	printf("%s\n\n", expected_output);
	destroy_arr(env);
}

static t_vararr	*init_env(int has_env)
{
	t_vararr	*env;

	env = make_new_arr(0);
	if (!has_env)
		return (env);
	else
	{
		append_element(env, "SHELL=/bin/bash");
		append_element(env, "PWD=Users/hocsong/Documents/minishell/ms1");
		append_element(env, "LOGNAME=hocsong");
		append_element(env, "LaunchInstanceID=1525446E-700F-4494-A67E-8DD2AF55B79B");
		append_element(env, "HOME=/Users/hocsong");
		append_element(env, "PWD=Users/hocsong/Documents/minishell/ms1");
		append_element(env, "PWD=Users/hocsong/Documents/minishell/ms1");
	}
	return (env);
}
