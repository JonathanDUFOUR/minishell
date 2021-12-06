/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/06 18:50:37 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "ft_mem.h"
#include "minishell.h"
#include "t_token_lst.h"
#include "ft_string.h"

#ifndef VAR_CHARS
# define VAR_CHARS	"\
	abcdefghijklmnopqrstuvwxyz\
	ABCDEFGHIJKLMNOPQRSTUVWXYZ\
	0123456789\
	_"
#endif

static bool	__is_valid(const char *str)
{
	char	*tmp;

	tmp = (char *)str;
	while (*tmp && *tmp != '=')
	{
		if (ft_strchr(VAR_CHARS, *tmp) == NULL)
			return (false);
		tmp++;
	}
	return (true);
}

int	main(int argc, char **argv, char **envp)
{
	char	*str = "Salut:=lol";

	(void)argc;
	(void)argv;
	(void)envp;
	if (__is_valid(str) == true)
		puts("true");
	else
		puts("false");
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
