/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:21 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/21 01:26:16 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "ft_io.h"
#include "ft_string.h"
#include "minishell.h"

unsigned int	g_exit_status;

static int	__clear_quit(char const *prompt, char const *line,
	t_token_lst *const tokens, int const ret)
{
	ft_memdel(&prompt);
	ft_memdel(&line);
	rl_clear_history();
	token_lst_clear(tokens);
	return (ret);
}

static int	__process_one(t_env_lst *const env, char const *program,
	t_token_lst *tokens, char const **line)
{
	char const	*prompt = NULL;

	if (token_lst_get(tokens, env, *line))
		return (__clear_quit(prompt, *line, tokens, EXIT_FAILURE));
	if (**line)
		add_history(*line);
	ft_memdel(line);
	if (token_lst_syntax_check(tokens, program))
		;
	else if (token_lst_here_doc(tokens, env, program))
		return (__clear_quit(prompt, *line, tokens, EXIT_FAILURE));
	else if (g_exit_status == (1 << 7))
		g_exit_status |= SIGINT;
	else if (tokens->size && token_lst_exec(tokens, env, program))
		return (__clear_quit(prompt, *line, tokens, EXIT_FAILURE));
	token_lst_clear(tokens);
	prompt = prompt_get(env, program);
	*line = readline(prompt);
	ft_memdel(&prompt);
	return (EXIT_SUCCESS);
}

static int	__command_line(t_env_lst *const env, char const *program)
{
	t_token_lst	tokens;
	char const	*prompt = prompt_get(env, program);
	char const	*line = readline(prompt);

	ft_bzero(&tokens, sizeof(t_token_lst));
	ft_memdel(&prompt);
	while (line)
		if (__process_one(env, program, &tokens, &line))
			return (EXIT_FAILURE);
	return (__clear_quit(prompt, line, &tokens, EXIT_SUCCESS));
}

int	main(int const ac, char const *const *av, char const *const *ep)
{
	t_env_lst	env;

	if (ac != 1)
		return (usage_err(av[0]));
	g_exit_status = 0;
	ft_bzero(&env, sizeof(t_env_lst));
	if (sigall_default()
		|| env_lst_init(&env, ep)
		|| __command_line(&env, av[0]))
	{
		env_lst_clear(&env);
		perror(av[0]);
		return (EXIT_FAILURE);
	}
	env_lst_clear(&env);
	printf("exit\n");
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	return (g_exit_status);
}
