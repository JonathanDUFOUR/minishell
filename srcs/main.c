/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:21 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/17 21:43:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "ft_io.h"
#include "ft_string.h"
#include "minishell.h"
#include "execution.h"

unsigned int	g_exit_status;

static int	__clear_quit(char const *line, t_token_lst *const tokens,
	int const ret)
{
	ft_memdel(&line);
	rl_clear_history();
	token_lst_clear(tokens);
	return (ret);
}

static bool	__isexit(t_token const *node)
{
	while (node)
	{
		if (node->type == T_BUILTIN && !ft_strcmp(node->str, "exit"))
			return (true);
		node = node->next;
	}
	return (false);
}

static int	__run(t_token_lst *const tokens, t_env_lst *const env,
	char const *program)
{
	t_exedata	data;
	int			termin;
	int			termout;

	if (sigall_mute() || exedata_init(&data, env, program))
		return (EXIT_FAILURE);
	if (token_lst_type_count(tokens, T_PIPE)
		|| token_lst_type_count(tokens, T_COMMAND))
		return (pipeline(tokens, env, &data) | exedata_clear(&data));
	termin = dup(STDIN_FILENO);
	termout = dup(STDOUT_FILENO);
	if ((termin == -1 || termout == -1 || __isexit(tokens->head))
		&& ft_fddel(&termin) | ft_fddel(&termout))
		return (exedata_clear(&data) | EXIT_FAILURE);
	if (exec_cmd(tokens, tokens->head, env, &data))
		return (exedata_clear(&data) | ft_fddel(&termin) | ft_fddel(&termout)
			| EXIT_FAILURE);
	if ((close(STDIN_FILENO) | close(STDOUT_FILENO)) == -1
		|| dup2(termin, STDIN_FILENO) == -1
		|| dup2(termout, STDOUT_FILENO) == -1
		|| (ft_fddel(&termin) | ft_fddel(&termout)))
		return (exedata_clear(&data) | ft_fddel(&termin) | ft_fddel(&termout)
			| EXIT_FAILURE);
	return (exedata_clear(&data) | sigall_default() | EXIT_SUCCESS);
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
		else if (g_exit_status == (1 << 7))
			g_exit_status |= SIGINT;
		else if (__run(&tokens, env, program))
			return (__clear_quit(line, &tokens, EXIT_FAILURE));
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
		return (usage_err(av[0]));
	g_exit_status = 0;
	ft_bzero(&env, sizeof(t_env_lst));
	if (sigall_default()
		|| env_lst_init(&env, ep)
		|| __get_command_line(&env, av[0]))
	{
		env_lst_clear(&env);
		perror(av[0]);
		return (EXIT_FAILURE);
	}
	env_lst_clear(&env);
	printf("Bye Bye\n");
	return (EXIT_SUCCESS);
}
