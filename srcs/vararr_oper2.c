/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vararr_oper2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:37:11 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/06 11:48:13 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vararr.h"

char		*get_element(t_vararr *varr, int idx);
char		*find_element(t_vararr *varr, char *val);
char		*append_element(t_vararr *varr, char *val);
char		*update_element(t_vararr *varr, char *key, char *value);