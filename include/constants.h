/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:28:13 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/11 14:33:44 by hyunjuki         ###   ########.fr       */
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
	NO_QUOTE = -1,
	SWITCH_OFF = 0,
	SWITCH_ON = 1,
};

#endif