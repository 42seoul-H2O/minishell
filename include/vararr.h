/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vararr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:13:54 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/06 11:28:52 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARARR_H
# define VARARR_H

/*
** capacity : array max size
** len : array current size
*/
typedef struct s_vararr
{
	int		capacity;
	int		len;
	char	**arr;
}				t_vararr;

char		*get_element(t_vararr *arr, int idx);
char		*find_element(t_vararr *arr, char *val);
char		*append_element(t_vararr *arr, char *val);
char		*update_element(t_vararr *arr, char *key, char *value);

t_vararr	make_new_arr(int size);
int			free_arr(char **arr);
void		destroy_arr(t_vararr *arr);
int			realloc_2x_arr(t_vararr *arr);
char		**copy_arr(t_vararr *arr);

char		*ft_getenv(t_vararr *env, char *key);
char		*ft_setenv(t_vararr *env, char *key, char *value, int overwrite);
int			ft_unsetenv(t_vararr *env, char *key);
void		print_all_env(char **env);

#endif