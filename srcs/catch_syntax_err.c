/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_syntax_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:59:47 by hocsong           #+#    #+#             */
/*   Updated: 2023/02/20 18:28:36 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	catch_pipe_err(t_parsed *parsed);
static void	catch_no_token_after_op(t_parsed *parsed);
static void	catch_contiguous_ops(t_parsed *parsed);
static int	is_redir(char *word);

void	catch_syntax_err(t_parsed *parsed)
{
	catch_pipe_err(parsed);
	catch_no_token_after_op(parsed);
	catch_unmatching_quotes(parsed);
	catch_contiguous_ops(parsed);
}

static void	catch_pipe_err(t_parsed *parsed)
{
	if (parsed->words_count == -1)
		return ;
	if (parsed->words[0] && get_optype(parsed->words[0]) == PIPE)
	{
		parsed->words_count = -1;
		return ;
	}
}

static void	catch_no_token_after_op(t_parsed *parsed)
{
	if (parsed->words_count == -1 || !parsed->words_count)
		return ;
	if (get_optype(parsed->words[parsed->words_count - 1]))
	{
		parsed->words_count = -1;
		return ;
	}
}

static void	catch_contiguous_ops(t_parsed *parsed)
{
	size_t	i;

	if (parsed->words_count == -1)
		return ;
	i = 0;
	while (parsed -> words[i])
	{
		if (0 < i && parsed->words[i] && ((is_redir(parsed -> words[i - 1]) \
		&& get_optype(parsed -> words[i])) \
		|| (get_optype(parsed -> words[i - 1]) == PIPE \
		&& get_optype(parsed -> words[i]) == PIPE)))
		{
			parsed -> words_count = -1;
			return ;
		}
		i++;
	}
}

static int	is_redir(char *word)
{
	int	optype;

	optype = get_optype(word);
	if (optype == REDIR_IN \
		|| optype == REDIR_OUT \
		|| optype == APPEND \
		|| optype == HEREDOC)
		return (1);
	return (0);
}
