/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vararr_oper3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:37:48 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/06 11:37:55 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vararr.h"

char		*ft_getenv(t_vararr *env, char *key);
char		*ft_setenv(t_vararr *env, char *key, char *value, int overwrite);
int			ft_unsetenv(t_vararr *env, char *key);
void		print_all_env(char **env);