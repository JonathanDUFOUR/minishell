/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:18:52 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/03 19:29:39 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "e_ret.h"
#include "t_env_lst.h"
#include "t_token_lst.h"
#include "ft_io.h"

// sans option ni argument --> s'il y a l'un ou l'autre c'est une erreur
int	msh_env(t_token *args, t_env_lst *data)
{
	t_env	*elem;

	if (!data)
		return (FAILURE);
	if (args != NULL) // TODO testes les options et arguments
	{
		if (args->type == T_OPTION)
			return (error_option("env: ", args));
		if (args->type == T_ARGUMENT)
		{
			ft_putendl_fd("env: too many arguments", STDERR_FILENO);
			return (FAILURE);
		}
	}
	elem = data->head;
	while (elem)
	{
		printf("%s=%s\n", elem->name, elem->value);
		elem = elem->next;
	}
	return (SUCCESS);
}
