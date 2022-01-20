/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:19:09 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 10:26:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

int	msh_pwd(t_env_lst *const env __attribute__((unused)), t_token *const token)
{
	char	*buf;

	if (token && token->next && token->next->type == T_OPTION)
		return (error_option("pwd: ", token->next->str));
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
