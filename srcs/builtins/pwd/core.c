/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:19:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/08 14:43:32 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "t_token_lst.h"

int	msh_pwd(t_token *args)
{
	char	*buf;

	if (args && args->type == T_OPTION)
		return (error_option("pwd: ", args));
	buf = NULL;
	buf = getcwd(buf, 0);
	if (buf == NULL)
		return (EXIT_FAILURE);
	if (printf("%s\n", buf) < 0)
	{
		free(buf);
		return (EXIT_FAILURE);
	}
	free(buf);
	return (EXIT_SUCCESS);
}
