/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:21 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 02:00:26 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "ft_string.h"
#include "minishell.h"
#include "redirections.h"

unsigned int	g_exit_status;

static int	__clear_quit(char const *line, t_token_lst *const tokens,
	int const ret)
{
	ft_memdel(&line);
	rl_clear_history();
	token_lst_clear(tokens);
	return (ret);
}

static int	__backup_in_out(int fd_in_out[2])
{
	fd_in_out[0] = dup(STDIN_FILENO);
	fd_in_out[1] = dup(STDOUT_FILENO);
	if (fd_in_out[0] == -1 || fd_in_out[1] == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	__restore_in_out(int fd_in_out[2])
{
	int	ret;

	ret = 0;
	ret += dup2(fd_in_out[0], STDIN_FILENO);
	ret += close(fd_in_out[0]);
	ret += dup2(fd_in_out[1], STDOUT_FILENO);
	ret += close(fd_in_out[1]);
	if (ret < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	__run(t_token_lst *const tokens, t_env_lst *const env)
{
	t_exec_data	data;
	int			ret;
	int			fd_in_out[2];

	if (token_lst_type_count(tokens, T_PIPE)
		|| token_lst_type_count(tokens, T_COMMAND))
		return (pipeline(tokens, env));
	if (data_init(&data, env))
		return (EXIT_FAILURE);
	if (__backup_in_out(fd_in_out))
	{
		data_clear(&data);
		return (EXIT_FAILURE);
	}
	ret = exec_cmd(tokens, tokens->head, env, &data);
	ret += __restore_in_out(fd_in_out);
	data_clear(&data);
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
		else if (g_exit_status == (1 << 7))
			g_exit_status |= SIGINT;
		else if (__run(&tokens, env))
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
