/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_redir_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:47:18 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/18 12:49:17 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "constants.h"

static void	merge_redir_token(t_str *str, int idx);
static int	get_redir_in_s(t_str *str, int redir_order, int optype);
static void	merge(t_str *str, int idx);
static int	should_merge(t_str *str, int idx, int optype);

void	merge_redir_tokens(t_str *str)
{
	int	i;

	i = 0;
	while (str -> words[i])
	{
		merge_redir_token(str, i);
		i++;
	}
}

static void	merge_redir_token(t_str *str, int idx)
{
	if (get_optype(str -> words[idx]) == REDIR_IN \
		&& get_optype(str -> words[idx + 1]) == REDIR_IN \
		&& should_merge(str, idx, REDIR_IN))
		merge(str, idx);
	else if (get_optype(str -> words[idx]) == REDIR_OUT \
		&& get_optype(str -> words[idx + 1]) == REDIR_OUT \
		&& should_merge(str, idx, REDIR_OUT))
		merge(str, idx);
}

static int	should_merge(t_str *str, int idx, int optype)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str -> words[i] && i <= idx)
	{
		if (get_optype(str -> words[i]) == optype)
			count++;
		i++;
	}
	return (get_redir_in_s(str, count + str -> merge_count, optype));
}

static int	get_redir_in_s(t_str *str, int redir_order, int optype)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str -> s[i] && count < redir_order)
	{
		if (str -> s[i] == optype)
			count++;
		i++;
	}
	if (str -> s[i] == optype)
		return (1);
	return (0);
}

static void	merge(t_str *str, int idx)
{
	char	*temp;

	temp = str -> words[idx];
	str -> words[idx] = ft_strjoin(str -> words[idx], str -> words[idx + 1]);
	free(temp);
	free(str -> words[idx + 1]);
	idx++;
	while (str -> words[idx])
	{
		str -> words[idx] = str -> words[idx + 1];
		idx++;
	}
	str -> words[idx] = 0;
	str -> merge_count = str -> merge_count + 2;
}
