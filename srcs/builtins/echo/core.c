/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:18:47 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/07 14:35:32 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "t_token_lst.h"
#include "ft_string.h"

void	msh_echo(t_token *args)
{
	bool	option_n;

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
			printf("%s ", args->str);
			args = args->next;
		}
		printf("\b");
	}
	if (option_n == false)
		printf("\n");
}
