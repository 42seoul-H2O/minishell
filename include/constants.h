/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:28:13 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/16 16:22:33 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

enum e_token_type
{
	EOA = -1,
	NO_QUOTE = -1,
	OFF = 0,
	ON = 1,
};

enum e_TOKEN_TYPE
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