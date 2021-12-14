/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:19:04 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/13 16:42:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "t_env_lst.h"
#include "t_token.h"
#include "ft_string.h"
#include "ft_io.h"
/* surprise */
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

static bool	__is_valid(const char *str)
{
	char	*tmp;
	int		len;

	tmp = (char *)str;
	len = 0;
	while (tmp[len] && tmp[len] != '=')
		len++;
	if (len == 0)
		return (false);
	while (*tmp && *tmp != '=')
	{
		if (ft_strchr(VAR_CHARS, *tmp) == NULL)
			return (false);
		tmp++;
	}
	return (true);
}

int	msh_export(t_env_lst *const env, t_token *args)
{
	if (args == NULL)
		return (__surprise());
	if (args->type == T_OPTION)
		return (error_option("export: ", args));
	while (args && args->type == T_ARGUMENT)
	{
		if (__is_valid(args->str) == false)
		{
			ft_putstr_fd("export: '", STDERR_FILENO);
			ft_putstr_fd(args->str, STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
		}
		else
		{
			if (put_env(args->str, env) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		args = args->next;
	}
	return (EXIT_SUCCESS);
}
