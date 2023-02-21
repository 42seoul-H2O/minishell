/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:28:13 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/21 12:01:39 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

enum e_cmd_type
{
	NO_CMD,
	ERROR,
	IS_DIR,
	EXECUTABLE,
	CD,
	ECHO,
	ENV,
	EXIT,
	EXPORT,
	PWD,
	UNSET,
};

enum e_token_type
{
	CMD = 1,
	ARG = 2,
	PIPE = 3,
	REDIR_WORD = 4,
	HEREDOC = 5,
	APPEND = 6,
	REDIR_IN = '<',
	REDIR_OUT = '>'
};

#endif