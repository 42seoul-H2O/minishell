/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vararr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:13:54 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/20 15:46:05 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARARR_H
# define VARARR_H

# include "../lib/libft/libft.h"

typedef struct s_vararr
{
	int		capacity;
	int		len;
	char	**arr;
}				t_vararr;

t_vararr	*make_new_arr(int size);
void		free_arr(char **arr);
void		destroy_arr(t_vararr *varr);
int			realloc_arr(t_vararr *varr, float ratio);
char		**copy_arr(t_vararr *varr, int idx);

char		*get_element(t_vararr *varr, int idx);
int			find_element(t_vararr *varr, char *val);
int			append_element(t_vararr *varr, char *val);
int			update_element(t_vararr *varr, char *key, char *value);
int			delete_element(t_vararr *varr, char *key);

char		*ft_getenv(t_vararr *env, char *key);
int			ft_setenv(t_vararr *env, char *key, char *value, int overwrite);
int			ft_unsetenv(t_vararr *env, char *key);
char		*join_key_value_string(char *key, char *value);

void		print_all_string(char *prefix, char **arr,
				int value_quote, int no_val);
int			math_min(int a, int b);

#endif