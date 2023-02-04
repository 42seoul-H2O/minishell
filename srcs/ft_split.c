/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:46:57 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/03 19:28:20 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

//TODO: quote의 짝이 맞지 않는 경우 에러를 내뱉도록 구현하자.
//TODO: NULL을 반환하는 대신, 적절한 에러 코드를 내뱉도록 exit 함수를 사용해야 함.

#include "minishell.h"

static int		word_count(char const *s, char *c);
static int		is_delimiter(char const *s, char *c, int idx);
static char		*create_word(char const *s, char *c, int start_idx);

char	**ft_split(char const *s, char *c)
{
	int		i;
	int		j;
	int		len;
	char	**strs;

	i = 0;
	j = 0;
	len = word_count(s, c);
	strs = malloc(sizeof (char *) * (len + 1));
	if (!strs)
		return (NULL);
	while (s[i])
	{
		if (is_delimiter(s, c, i - 1) && !is_delimiter(s, c, i))
		{
			strs[j] = create_word(s, c, i);
			j++;
		}
		i++;
	}
	if (word_count(s, c) <= 0)
		strs[0] = 0;
	strs[i] = (NULL);
	return (strs);
}

static int	word_count(char const *s, char *c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!is_delimiter(s, c, i)
			&& is_delimiter(s, c, i + 1))
			count++;
		i++;
	}
	return (count);
}

static int	is_delimiter(char const *s, char *c, int idx)
{
	size_t	i;

	i = 0;
	if (idx == -1 || !s[idx])
		return (1);
	while (c[i])
	{
		if (s[idx] == c[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*create_word(char const *s, char *c, int start_idx)
{
	int		word_len;
	char	*word;
	int		i;

	word_len = get_word_len(s, c, start_idx);
	i = 0;
	if (!word_len)
		exit (1);
	word = malloc(sizeof (char) * (word_len + 1));
	if (!word)
		exit (1);
	while (!is_delimiter(s, c, start_idx))
	{
		word[i] = s[start_idx];
		i++;
		start_idx++;
	}
	word[i] = 0;
	return (word);
}
