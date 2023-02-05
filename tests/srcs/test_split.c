/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:30:48 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/04 17:48:23 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tests.h"
#include <stdarg.h>

static void	test_split_implementation(char *s, int word_count, ...);

void	test_split(void)
{
	printf("---- Split Test Cases ----\n");

	// test_split_implementation("abcdefg", 1, "abcdefg");
	// test_split_implementation("", 1, "");
	test_split_implementation("ls -la | wc -l", 5, "ls", "-la", "|", \
		"wc", "-l");
	printf("---- End of Split ----\n\n");
}

static void	test_split_implementation(char *s, int word_count, ...)
{
	int		i;
	va_list	ap;
	char	**words;

	i = 0;
	words = my_split(s, " \t<>|", "<>|");
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
