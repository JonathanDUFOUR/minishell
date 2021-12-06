/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:19:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/06 18:14:18 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"
#include "t_token.h"
#include "ft_io.h"
#include "ft_string.h"

int	msh_unset(t_env_lst *data, t_token *args)
{
	if (args == NULL)
		return (EXIT_SUCCESS);
	if (args->type == T_OPTION)
		return (error_option("unset: ", args));
	while (args && args->type == T_ARGUMENT)
	{
		if (ft_strchr(args->str, '=') != NULL) // TODO verifier que str est valide (alnum + _ + len > 0)
		{
			ft_putstr_fd("unset: ", STDERR_FILENO);
			ft_putstr_fd(args->str, STDERR_FILENO);
			ft_putendl_fd("not a valid identifier", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		unset_env(args->str, data);
		args = args->next;
	}
	return (EXIT_SUCCESS);
}
