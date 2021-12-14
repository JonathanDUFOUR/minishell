/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:16:28 by majacque          #+#    #+#             */
/*   Updated: 2021/12/14 12:43:16 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

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
	elem = elem->next;
	while (elem && (elem->type != T_COMMAND && elem->type != T_BUILTIN))
		elem = elem->next;
	return (elem);
}

int	pipeline(t_token_lst *tokens, t_env_lst *env)
{
	t_token	*elem;
	pid_t	pid;
	int		status;
	int		cmd_n;
	int		i;

	elem = tokens->head;
	cmd_n = __count_cmd(tokens);
	i = 0;
	while (i < cmd_n)
	{
		if (elem->type == T_COMMAND)
		{ // TODO dans un fonction()
			pid = fork();
			if (pid == -1)
				return (EXIT_FAILURE);
			if (pid == 0)
			{
				/*exec*/
			}
			if (waitpid(pid, &status, 0) == -1)
			{
				/*erreur*/
				return (EXIT_FAILURE);
			}
		}
		else
		{
			/*exec le builtin*/
		}
		elem = __next_command(elem);
		i++;
	}
}
