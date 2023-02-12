/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:33:59 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/12 18:23:11 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"
#include "vararr.h"
#include "builtin.h"
#include "tests.h"

static void		print_words(t_str *str);
static void		print_expected_outputs(va_list ap, int count);
static void		parser_test(char *input, int has_env, int word_count, ...);
static t_vararr	*init_env(int has_env);

void	test_parser(void)
{
	printf("---- Parser Test Cases ----\n\n");
	parser_test("blahblah $", HAS_ENV, 2, "blahblah", "$");
	parser_test("blahblah $^", HAS_ENV, 2, "blahblah", "$^");
	parser_test("blahblah $\'\'", HAS_ENV, 2, "blahblah", "$");
	parser_test("blahblah $\'PATH\'", HAS_ENV, 2, "blahblah", "$PATH");
	parser_test("blahblah $\"PATH\"", HAS_ENV, 2, "blahblah", "$PATH");
	parser_test("blahblah \"$\"PATH", HAS_ENV, 2, "blahblah", "$PATH");
	parser_test("blahblah \"$\'PATH\"", HAS_ENV, 2, "blahblah", "$\'PATH");
	parser_test("blahblah \'$\"PATH\'", HAS_ENV, 2, "blahblah", "$\"PATH");
	parser_test("blahblah \'\"$PATH\"\'", HAS_ENV, 2, "blahblah", "\"$PATH\"");
	parser_test("blahblah \'$HOME\'", HAS_ENV, 2, "blahblah", "$HOME");
	parser_test("blahblah \"$HOME\"", HAS_ENV, 2, "blahblah", "/Users/hocsong");
	parser_test("$SHELL$LOGNAME", HAS_ENV, 1, "/bin/bashhocsong");
	parser_test("\"$HOME \'$SHELL\'\"", HAS_ENV, 1, "/Users/hocsong \'/bin/bash\'"); // 실패.
	parser_test("blahblah $", NOT_HAVE_ENV, 2, "blahblah", "$");
	parser_test("blahblah $\"dff\"", HAS_ENV, 2, "blahblah", "$dff");
	parser_test("blahblah $\"dff\"", NOT_HAVE_ENV, 2, "blahblah", "$dff");
	parser_test("blahblah $\"LOGNAME\"", HAS_ENV, 2, "blahblah", "$LOGNAME");
	parser_test("blahblah $\"LOGNAME\"", NOT_HAVE_ENV, 2, "blahblah", "$LOGNAME");
	parser_test("blahblah$", HAS_ENV, 1, "blahblah$");
	parser_test("blahblah$", NOT_HAVE_ENV, 1, "blahblah$");
	parser_test("blahblah $.", HAS_ENV, 2, "blahblah", "$.");
	parser_test("blahblah $.", NOT_HAVE_ENV, 2, "blahblah", "$.");
	parser_test("$HOME is defined!", HAS_ENV, 3, "/Users/hocsong", "is", "defined!");
	parser_test("$HOMEI is undefined!", HAS_ENV, 3, "", "is", "undefined!");
	parser_test("$yadi", HAS_ENV, 1, "");
	parser_test("$yadi", NOT_HAVE_ENV, 1, "");
	parser_test("$", HAS_ENV, 1, "$");
	parser_test("$.", HAS_ENV, 1, "$.");
	parser_test("$,", HAS_ENV, 1, "$,");
	parser_test("$\'\'", HAS_ENV, 1, "$");
	parser_test("abc$SHELL\'ab\'", HAS_ENV, 1, "abc/bin/bashab");
	parser_test("abc$SHELL\'ab\'", NOT_HAVE_ENV, 1, "abcab");
	parser_test("abc$ABC^yap ", HAS_ENV, 1, "abc^yap");
	//Test cases with more than one $
	parser_test("blahblah $$", HAS_ENV, 2, "blahblah", "$$");
	parser_test("blahblah $$$", HAS_ENV, 2, "blahblah" , "$$$");
	parser_test("blahblah $ $", HAS_ENV, 3, "blahblah", "$", "$");
	parser_test("blahblah $ $", NOT_HAVE_ENV, 3, "blahblah", "$", "$");
	parser_test("blahblah $\"dff\" $", HAS_ENV, 3, "blahblah", "$dff", "$");
	parser_test("blahblah $\"dff\" $", NOT_HAVE_ENV, 3, "blahblah", "$dff", "$");
	parser_test("ab\"\"\"\"", HAS_ENV, 1, "ab");
	parser_test("ab\"\'\"\"\"", HAS_ENV, 1, "ab\'");
	parser_test("", HAS_ENV, 1, ""); // 이 케이스와 아래 케이스는, 빈 문자열이 반환되는 게 맞는지 따로 체크할 필요가 있다. 출력 값만 봐서는 알 수 없음.
	parser_test(" ", HAS_ENV, 1, "");
	printf("---- End of Parser ----\n\n");
	// quote의 짝이 안 맞는 경우에 대한 테스트 코드가 없다.
}

static void	parser_test(char *input, int has_env, int word_count, ...)
{
	t_str		str;
	t_vararr	*env;
	va_list		ap;

	va_start(ap, word_count);
	env = init_env(has_env);
	printf("---- Test Case: %s ----\n", input);
	printf("---- has_envp: %d ----\n", has_env);
	str = parse(input, env);
	printf("---- Output ----\n");
	print_words(&str);
	printf("---- Expected Output ----\n");
	print_expected_outputs(ap, word_count);
	destroy_arr(env);
	va_end(ap);
}

static t_vararr	*init_env(int has_env)
{
	t_vararr	*env;

	env = make_new_arr(10);
	if (has_env == NOT_HAVE_ENV)
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

static void	print_words(t_str *str)
{
	size_t	i;

	i = 0;
	while (str -> words[i])
	{
		printf("%s\n", str -> words[i]);
		i++;
	}
}

static void	print_expected_outputs(va_list ap, int count)
{
	char	*word;
	int		i;

	i = 0;
	while (i < count)
	{
		word = va_arg(ap, char *);
		printf("%s\n", word);
		i++;
	}
}
