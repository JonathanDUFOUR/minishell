/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/08 11:33:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "ft_mem.h"
#include "minishell.h"
#include "t_token_lst.h"
#include "g_line.h"

static int	__get_command_line(void)
{
	t_token_lst	tokens;

	ft_bzero(&tokens, sizeof(t_token_lst));
	g_line = readline(PROMPT);
	while (g_line)
	{
		if (token_lst_get(&tokens, g_line))
		{
			token_lst_clear(&tokens);
			rl_clear_history();
			ft_memdel(&g_line);
			return (EXIT_FAILURE);
		}
		token_lst_clear(&tokens);
		add_history(g_line);
		ft_memdel(&g_line);
		g_line = readline(PROMPT);
	}
	rl_clear_history();
	return (EXIT_SUCCESS);
}

int	main(void)
{
	if (set_sigint_handle())
	{
		perror("minishell");
		return (EXIT_FAILURE);
	}
	if (set_sigquit_handle())
	{
		perror("minishell");
		return (EXIT_FAILURE);
	}
	if (__get_command_line())
	{
		perror("minishell");
		return (EXIT_FAILURE);
	}
	printf("Bye Bye\n");
	return (EXIT_SUCCESS);
}
