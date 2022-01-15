/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:18:47 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 07:33:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "t_token_lst.h"
#include "t_env_lst.h"
#include "ft_string.h"

int	msh_echo(t_env_lst *const env __attribute__((unused)), t_token *const token)
{
	t_token const	*args = token->next;
	bool			option_n;

	option_n = false;
	if (args != NULL)
	{
		if (args->type == T_OPTION && !ft_strcmp("-n", args->str))
		{
			args = args->next;
			option_n = true;
		}
		while (args && (args->type == T_OPTION || args->type == T_ARGUMENT))
		{
			printf("%s", args->str);
			args = args->next;
			if (args && (args->type == T_OPTION || args->type == T_ARGUMENT))
				printf(" ");
		}
	}
	if (option_n == false)
		printf("\n");
	return (EXIT_SUCCESS);
}

/*
	echo	tutu
*/
