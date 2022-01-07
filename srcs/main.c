/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:21 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/06 20:30:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "ft_io.h"
#include "ft_string.h"
#include "ft_colors.h"
#include "minishell.h"

unsigned int	g_exit_status;

static int	__usage_error(char const *program)
{
	ft_putendl_fd(RED "Error: Wrong usage" RESET, STDERR_FILENO);
	ft_putstr_fd("Usage: ./", STDERR_FILENO);
	ft_putendl_fd(program, STDERR_FILENO);
	return (EXIT_FAILURE);
}

static int	__clear_quit(char const *line, t_token_lst *const tokens,
	int const ret)
{
	ft_memdel(&line);
	rl_clear_history();
	token_lst_clear(tokens);
	return (ret);
}

static int	__get_command_line(t_env_lst *const env, char const *program)
{
	t_token_lst	tokens;
	char const	*line = readline(PROMPT);

	ft_bzero(&tokens, sizeof(t_token_lst));
	while (line)
	{
		if (token_lst_get(&tokens, line, env))
			return (__clear_quit(line, &tokens, EXIT_FAILURE));
		if (*line)
			add_history(line);
		ft_memdel(&line);
		if (token_lst_syntax_check(&tokens, program))
			g_exit_status = 2;
		else if (token_lst_here_doc(&tokens, env, program))
			return (__clear_quit(line, &tokens, EXIT_FAILURE));
		if (g_exit_status == (1 << 7))
			g_exit_status |= SIGINT;
		else if (pipeline(&tokens, env))
		{
			perror("pipeline");
			return (__clear_quit(line, &tokens, EXIT_FAILURE));
		}
		token_lst_clear(&tokens);
		line = readline(PROMPT);
	}
	rl_clear_history();
	return (EXIT_SUCCESS);
}

int	main(int const ac, char const *const *av, char const *const *ep)
{
	t_env_lst	env;

	if (ac != 1)
		return (__usage_error(av[0]));
	g_exit_status = 0;
	ft_bzero(&env, sizeof(t_env_lst));
	if (sigint_default()
		|| sigquit_default()
		|| sigterm_default()
		|| init_env(&env, ep)
		|| __get_command_line(&env, av[0]))
	{
		env_clear(&env);
		perror(av[0]);
		return (EXIT_FAILURE);
	}
	env_clear(&env);
	printf("Bye Bye\n");
	return (EXIT_SUCCESS);
}
