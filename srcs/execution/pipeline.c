/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:16:28 by majacque          #+#    #+#             */
/*   Updated: 2021/12/14 16:39:08 by majacque         ###   ########.fr       */
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

static char **get_path_env(t_env_lst *env)
{
	char	**path;
	char	*env_path;

	env_path = get_env("PATH", env);
	if (env_path == NULL)
		return (NULL);
	path = ft_split(env_path, ':');
	return (path);
}

int	pipeline(t_token_lst *tokens, t_env_lst *env)
{
	t_token	*elem;
	pid_t	pid;
	int		status;
	int		cmd_n;
	int		i;
	char	**path;
	char	**envp;

	elem = tokens->head;
	cmd_n = __count_cmd(tokens);
	i = 0;
	/*recuperer PATH avec un split*/
	path = get_path_env(env);
	/*recuperer l'environnemnt avec env_to_envp*/
	envp = env_to_envp(env);
	while (i < cmd_n)
	{
		if (elem->type == T_COMMAND)
		{ // TODO dans un fonction()
			pid = fork();
			if (pid == -1)
				return (EXIT_FAILURE);
			if (pid == 0)
			{
				// TODO open + redirections
				// TODO close les fd pas utiliser
				// TODO exec
				/*exec*/
				/*|--> recuperer la commande avec tokens_to_aa()*/
				/*|--> recuperer le chemin absolu vers la commande*/
				/*|--> execve*/
			}
			if (waitpid(pid, &status, 0) == -1)
			{
				/*erreur*/
				return (EXIT_FAILURE);
			}
		}
		else
		{
			// TODO exec le builtin avec une lookup table
		}
		elem = __next_command(elem);
		i++;
	}
	/*clean path, envp*/
	free(path);
	free_tab2d(envp);
	return (EXIT_SUCCESS);
}
