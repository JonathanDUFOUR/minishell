/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:18:47 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/17 19:16:37 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ft_string.h"
#include "t_token_lst.h"

static bool	__is_n(const char *const str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

int	msh_echo(t_env_lst *const env __attribute__((unused)), t_token *const token)
{
	t_token const	*args = token->next;
	bool			option_n;

	option_n = false;
	if (args != NULL)
	{
		while (args && args->type == T_OPTION && __is_n(args->str))
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
