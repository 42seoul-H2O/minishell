/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:57:18 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/10 16:37:51 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "builtin.h"

static void	del_char(char **s, size_t i);

void	remove_quotes(t_str *str)
{
	size_t	i;
	size_t	j;
	t_str	*temp;

	i = 0;
	while (str -> words[i])
	{
		j = 0;
		temp = malloc(sizeof (t_str));
		init_t_str(temp, str -> words[i]);
		while (temp -> s[j])
		{
			if ((temp -> s[j] == '\'' || temp -> s[j] == '\"') \
				&& is_quoted(temp, j))
				del_char(str -> words + i, j);
			j++;
		}
		free(temp);
		i++;
	}
}

static void	del_char(char **s, size_t i)
{
	char	*pre;
	char	*post;
	char	*new;

	pre = malloc(sizeof (char) * ft_strlen(*s) + 1);
	post = malloc(sizeof (char) * ft_strlen(*s) + 1);
	if (!pre || !post)
		builtin_exit(12);
	if (i == 0)
		pre[0] = 0;
	else
		ft_strlcpy(pre, *s, i);
	ft_strlcpy(post, *s + i + 1, ft_strlen(*s));
	new = ft_strjoin(pre, post);
	free(pre);
	free(post);
	free(*s);
	*s = new;
}
