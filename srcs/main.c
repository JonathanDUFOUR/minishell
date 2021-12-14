/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/14 20:06:51 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "ft_io.h"
#include "ft_mem.h"
#include "ft_colors.h"
#include "minishell.h"
#include "sgt_line.h"

int	g_exit_status;

static int	__usage_error(void)
{
	ft_putendl_fd(RED "Error: Wrong usage" RESET, STDERR_FILENO);
	ft_putendl_fd("Usage: ./minishell", STDERR_FILENO);
	return (EXIT_FAILURE);
}

static int	__get_command_line(t_env_lst *const env)
{
	t_token_lst	tokens;

	ft_bzero(&tokens, sizeof(t_token_lst));
	*sgt_line() = readline(PROMPT);
	while (*sgt_line())
	{
		if (token_lst_get(&tokens, *sgt_line(), env))
		{
			token_lst_clear(&tokens);
			rl_clear_history();
			ft_memdel(sgt_line());
			return (EXIT_FAILURE);
		}
		token_lst_print(&tokens);
		token_lst_clear(&tokens);
		add_history(*sgt_line());
		ft_memdel(sgt_line());
		*sgt_line() = readline(PROMPT);
	}
	rl_clear_history();
	return (EXIT_SUCCESS);
}

int	main(int const ac, char const *const *av, char const *const *ep)
{
	t_env_lst	env;

	(void)av;
	if (ac != 1)
		return (__usage_error());
	g_exit_status = 0;
	ft_bzero(&env, sizeof(t_env_lst));
	if (set_sigint_handle()
		|| set_sigquit_handle()
		|| init_env(&env, ep)
		|| __get_command_line(&env))
	{
		env_clear(&env);
		perror("minishell");
		return (EXIT_FAILURE);
	}
	env_clear(&env);
	printf("Bye Bye\n");
	return (EXIT_SUCCESS);
}
