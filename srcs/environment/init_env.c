/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:52:00 by majacque          #+#    #+#             */
/*   Updated: 2021/12/06 12:27:45 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"

int	init_env(t_env_lst *data, char **envp)
{
	t_env	*new;
	int		i;
	
	data->head = NULL;
	data->tail = NULL;
	data->size = 0;
	i = -1;
	while (envp[++i])
	{
		new = env_new(envp[i]);
		if (new == NULL)
		{
			env_clear(data);
			return (EXIT_FAILURE);
		}
		env_addback(data, new);
	}
	return (EXIT_SUCCESS);
}
