/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:30:48 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/15 12:27:56 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "tests.h"

static void	test_split_implementation(char *s, int word_count, ...);

void	test_split(void)
{
	printf("---- Split Test Cases ----\n");

	test_split_implementation("ls -la |wc -l", 5, "ls", "-la", "|", "wc", "-l");
	test_split_implementation("ls -la ||wc -l", 6, "ls", "-la", "|", "|", "wc", "-l");
	test_split_implementation("ls -la | |wc -l", 6, "ls", "-la", "|", "|", "wc", "-l");
	test_split_implementation("ls -la | | wc -l", 6, "ls", "-la", "|", "|", "wc", "-l");
	test_split_implementation("abcdefg", 1, "abcdefg");
	test_split_implementation("", 1, "");
	test_split_implementation("ls -la | wc -l", 5, "ls", "-la", "|", "wc", "-l");
	test_split_implementation("echo -nnn	| find . <<", 7, "echo", "-nnn", "|", "find", ".", "<", "<");
	test_split_implementation("echo -nnn	| find . ab<<", 8, "echo", "-nnn", "|", "find", ".", "ab", "<", "<");
	test_split_implementation("echo -n \"||\" wc -l", 5, "echo", "-n", "\"||\"", "wc", "-l");
	test_split_implementation("echo -n\"|\" \"wc -l\"", 3, "echo", "-n\"|\"", "\"wc -l\"");
	test_split_implementation("echo -n\"|\" \'wc -l\'", 3, "echo", "-n\"|\"", "\'wc -l\'");
	test_split_implementation("echo -n\'|\" \'wc -l\"\"", 3, "echo", "-n\'|\" \'wc", "-l\"\"");
	printf("---- End of Split ----\n\n");
}

static void	test_split_implementation(char *s, int word_count, ...)
{
	int		i;
	va_list	ap;
	char	**words;
	t_str	str;

	i = 0;
	init_t_str(&str, s);
	words = my_split(&str);
	printf("---- Test Case: %s ----\n", s);
	printf("---- Output ----\n");
	while (words[i])
	{
		printf("word[%d]: %s\n", i, words[i]);
		i++;
	}
	i = 0;
	printf("---- Expected Output ----\n");
	va_start(ap, word_count);
	while (i < word_count)
	{
		printf("word[%d]: %s\n", i, va_arg(ap, char *));
		i++;
	}
	va_end(ap);
	printf("\n");
}
