/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:57:18 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/12 14:43:59 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "builtin.h"

static void	del_char(char **s, size_t i);
static void	del_quotes(t_str *str);

void	remove_quotes(t_str *str)
{
	size_t	i;
	t_str	*temp;

	i = 0;
	while (str -> words[i])
	{
		temp = malloc(sizeof (t_str));
		if (!temp)
			builtin_exit(12);
		init_t_str(temp, str -> words[i]);
		del_quotes(temp);
		free(str -> words[i]);
		str -> words[i] = temp -> s;
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

static void	del_quotes(t_str *str)
{
	size_t	i;

	i = ft_strlen(str -> s) - 1;
	if (i < 0)
		return ;
	while (0 <= i)
	{
		if ((str -> s[i] == '\'' || str -> s[i] == '\"') && \
			!is_quoted(str, i))
			del_char(&(str -> s), i);
		i--;
	}
}
