/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:52:00 by majacque          #+#    #+#             */
/*   Updated: 2021/12/01 19:08:13 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_env_lst.h"

t_env_lst	init_env(char **envp) // TODO recuperer le nom et la valeur des variables dans la liste
{
	t_env_lst	env_lst;
	int			i;

	env_lst.head = NULL;
	env_lst.tail = NULL;
	env_lst.size = 0;
	i = 0;
	while (envp[i])
	{
		// ici
		i++;
	}
	return (env_lst);
}
