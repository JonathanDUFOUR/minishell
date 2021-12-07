/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/07 12:22:06 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "ft_mem.h"
#include "minishell.h"
#include "t_token_lst.h"

int	main(int argc, char **argv, char **envp)
{
	char		*line;
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
	return (EXIT_SUCCESS);
}
