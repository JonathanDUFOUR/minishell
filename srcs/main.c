/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/10 18:21:36 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "ft_mem.h"
#include "minishell.h"
#include "t_token_lst.h"
// DBG
#include "msh_cd.h"

int	main(int argc, char **argv, char **envp)
{
	char		*path = "//mnt/nfs/homes///majacque/./Work/GH_libft/../42pipex/.././minishell/libft_io///./";
	t_env_lst	env;
	t_token		arg;

	(void)argc;
	(void)argv;
	if (init_env(&env, envp) == EXIT_FAILURE)
	{
		perror("init_env");
		return (0);
	}
	arg.str = path;
	arg.type = T_ARGUMENT;
	arg.next = NULL;
	arg.prev = NULL;

	msh_cd(&env, &arg);
	printf("PWD = [%s]\n", get_env("PWD", &env));
	msh_pwd(NULL);
	env_clear(&env);
	return (0);
/* 	char		*line;
	t_token_lst	tokens;

	ft_bzero(&tokens, sizeof(tokens));
	line = readline(PROMPT);
	while (line)
	{
		if (token_lst_get(&tokens, line))
		{
			token_lst_clear(&tokens);
			ft_memdel(&line);
			perror("Error");
			exit(EXIT_FAILURE);
		}
		token_lst_clear(&tokens);
		ft_memdel(&line);
		line = readline(PROMPT);
	}
	printf("Bye Bye\n");
	return (EXIT_SUCCESS); */
}
