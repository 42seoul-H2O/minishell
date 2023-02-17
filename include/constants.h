/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:28:13 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/17 13:54:54 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

enum e_cmd_type
{
	ERROR,
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
	EOA = -1,
	NO_QUOTE = -1,
	OFF = 0,
	ON = 1,
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