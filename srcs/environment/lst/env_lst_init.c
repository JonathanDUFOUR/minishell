/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:52:00 by majacque          #+#    #+#             */
/*   Updated: 2022/01/15 08:47:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "t_env_lst.h"

/*
	Get the names and the values of environment variables
	and store them into a list
*/
int	env_lst_init(t_env_lst *const env, char const *const *envp)
{
	t_env	*new_elem;

	ft_bzero(env, sizeof(t_env_lst));
	while (*envp)
	{
		new_elem = env_new(*envp);
		if (new_elem == NULL)
		{
			env_lst_clear(env);
			return (EXIT_FAILURE);
		}
		env_lst_push_back(env, new_elem);
		++envp;
	}
	return (EXIT_SUCCESS);
}
