/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:19:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/03 19:22:27 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "e_ret.h"
#include "t_token_lst.h"

int	msh_pwd(t_token *args)
{
	char	*buf;

	if (args->type == T_OPTION)
		return (error_option("pwd: ", args));
	buf = NULL;
	buf = getcwd(buf, 0);
	if (buf == NULL)
	{
		perror("pwd: getcwd");
		return (FAILURE);
	}
	if (printf("%s\n", buf) < 0)
	{
		perror("pwd: printf");
		free(buf);
		return (FAILURE);
	}
	free(buf);
	return (SUCCESS);
}
