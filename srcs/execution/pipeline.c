/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:16:28 by majacque          #+#    #+#             */
/*   Updated: 2021/12/18 16:58:41 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

static int	__count_cmd(t_token_lst *tokens)
{
	int		count;
	t_token	*elem;

	count = 0;
	elem = tokens->head;
	while (elem)
	{
		if (elem->type == T_COMMAND || elem->type == T_BUILTIN)
			count++;
		elem = elem->next;
	}
}

static t_token	*__next_command(t_token *elem)
{
	while (elem && elem->type != T_PIPE)
		elem = elem->next;
	if (elem)
		return (elem->next);
	return (elem);
}

static char **__get_path_env(t_env_lst *env)
{
	char	**path;
	char	*env_path;

	env_path = get_env("PATH", env);
	if (env_path == NULL)
		return (NULL);
	path = ft_split(env_path, ':');
	return (path);
}

// TODO voir s'il serait pas mieux de mettre les tubes, envp, path dans une structure
int	pipeline(t_token_lst *tokens, t_env_lst *env)
{
	t_token	*elem;
	t_tube	tube_in;
	t_tube	tube_out;
	int		cmd_n;
	int		i;

	elem = tokens->head;
	cmd_n = __count_cmd(tokens);
	i = 0;
	if (pipe(tube_in) == -1)
		return (EXIT_FAILURE);
	if (pipe(tube_out) == -1)
		return (EXIT_FAILURE);
	while (i < cmd_n)
	{
		if ((i % 2) == 0)
			if (setup_fork(elem, env, tube_in, tube_out) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		else
			if (setup_fork(elem, env, tube_out, tube_in) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		elem = __next_command(elem);
		i++;
	}
	return (EXIT_SUCCESS);
}
