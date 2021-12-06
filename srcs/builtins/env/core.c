/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:18:52 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/06 17:52:15 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "t_env_lst.h"
#include "t_token_lst.h"
#include "ft_io.h"

int	msh_env(t_env_lst *data, t_token *args)
{
	t_env	*elem;

	if (args != NULL)
	{
		if (args->type == T_OPTION)
			return (error_option("env: ", args));
		if (args->type == T_ARGUMENT)
		{
			ft_putendl_fd("env: too many arguments", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
	}
	elem = data->head;
	while (elem)
	{
		printf("%s=%s\n", elem->name, elem->value);
		elem = elem->next;
	}
	return (EXIT_SUCCESS);
}
