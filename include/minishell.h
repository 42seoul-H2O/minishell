/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:07 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/05 13:18:02 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "constants.h"
# include "prompt.h"
# include "vararr.h"

int		init(t_vararr *env, char **envp);
int		init_env_arr(t_vararr *env, char **envp);

#endif