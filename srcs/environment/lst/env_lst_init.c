/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:52:00 by majacque          #+#    #+#             */
/*   Updated: 2022/01/20 11:58:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "t_env_lst.h"

/*
	Get names and values of variables contained in the given `envp`
	Transform them into env nodes
	Append the created nodes to the given env `lst`
*/
int	env_lst_init(t_env_lst *const lst, char const *const *envp)
{
	t_env	*new_elem;

	ft_bzero(lst, sizeof(t_env_lst));
	while (*envp)
	{
		new_elem = env_new(*envp);
		if (new_elem == NULL)
		{
			env_lst_clear(lst);
			return (EXIT_FAILURE);
		}
		env_lst_push_back(lst, new_elem);
		++envp;
	}
	return (EXIT_SUCCESS);
}
