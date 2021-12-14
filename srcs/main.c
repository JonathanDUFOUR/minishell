/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/14 10:58:21 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "ft_mem.h"
#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_token_lst	tokens;
	t_env_lst	env;

	(void)argc;
	(void)argv;
	g_exit_status = 0;
	init_env(&env, envp);
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
	env_clear(&env);
	printf("Bye Bye\n");
	return (EXIT_SUCCESS);
}
