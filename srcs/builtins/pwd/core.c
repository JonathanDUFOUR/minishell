/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:19:09 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 06:08:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "t_env_lst.h"
#include "t_token.h"

int	msh_pwd(t_env_lst *env __attribute__((unused)), t_token *token)
{
	char	*buf;

	if (token && token->next && token->next->type == T_OPTION)
		return (error_option("pwd: ", token->next));
	buf = getcwd(NULL, 0);
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
