/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:34 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/02/20 12:36:40 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_code = 0;

int	init(t_vararr **env, char **envp)
{
	char	*temp;

	set_sig_handler();
	*env = make_new_arr(30);
	if (!env)
		return (-1);
	if (init_env_arr(*env, envp) == -1)
		return (-1);
	temp = ft_getenv(*env, "SHLVL");
	if (!temp)
		temp = ft_strdup("1");
	else
		temp = ft_itoa(ft_atoi(temp) + 1);
	if (!temp)
		return (-1);
	ft_setenv(*env, "SHLVL", temp, 1);
	free(temp);
	return (0);
}

int	init_env_arr(t_vararr *env, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (append_element(env, envp[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_vararr	*env;

	if (init(&env, envp) == -1)
		return (-1);
	make_prompt(env);
	return (0);
}
