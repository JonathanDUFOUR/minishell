/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:19:04 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/06 18:54:59 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "t_env_lst.h"
#include "t_token.h"
#include "ft_string.h"
//surprise
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

#ifndef VAR_CHARS
# define VAR_CHARS	"\
	abcdefghijklmnopqrstuvwxyz\
	ABCDEFGHIJKLMNOPQRSTUVWXYZ\
	0123456789\
	_"
#endif

int	__surprise(void)
{
	char	*line;
	int		fd;

	fd = open("srcs/builtins/export/surprise", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	if (line)
		printf("%s\n", line);
	free(line);
	close(fd);
	return (EXIT_SUCCESS);
}

static bool	__is_valid(const char *str) // TODO verifier la len de str
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

int	msh_export(t_env_lst *data, t_token *args)
{
	if (args == NULL)
		return (__surprise());
	if (args->type == T_OPTION)
		return (error_option("export: ", args));
	while (args && args->type == T_ARGUMENT)
	{
		if (__is_valid(args->str) == false)
		{
			// message d'erreur
		}
		else
		{
			if (put_env(args->str, data) == EXIT_FAILURE)
			{
				perror("export");
				return (EXIT_FAILURE);
			}
		}
		// TODO verifier que NAME soit valide (alphanumerique + _ + len > 0)
		args = args->next;
	}
	return (EXIT_SUCCESS);
}
