/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:56:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/01 19:40:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEBUG */
#include <stdio.h>

#include <stdlib.h>
#include "t_token_lst.h"

static char const	*skip_token(char const *line)
{
	while (*line && *line != ' ')
		++line;
	while (*line && *line == ' ')
		++line;
	return (line);
}

int	token_lst_get(t_token_lst *const tokens, char const *line)
{
	while (*line)
	{
		printf("line: |%s|\n", line);
		line = skip_token(line);
	}
	return (EXIT_SUCCESS);
}
