/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_readline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:10:06 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/21 02:08:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_io.h"
#include "ft_string.h"
#include "minishell.h"

static int	__update_buff(char *buff)
{
	char const		*ptr = ft_strchr(buff, '\n') + 1;
	size_t const	len = ft_strlen(ptr);

	ft_memcpy(buff, ptr, len);
	buff[len] = 0;
	return (1);
}

/*
	Allocate a new string, put the address of the new string in the pointer
	pointed by the given pointer `line`
	Read one line from the stdin, and store it in the allocated area
	Return values
		 1: the line has been well read
		 0: an empty line with EOF has been reached
		-1: an error occured
*/
int	msh_readline(char const *prompt, char **const line)
{
	static char	buff[BUFFER_SIZE + 1] = {0};
	char		*tmp;
	ssize_t		rd;

	*line = ft_strcdup(buff, '\n');
	if (!*line)
		return (-1);
	ft_putstr_fd(prompt, STDOUT_FILENO);
	rd = read(STDIN_FILENO, buff, BUFFER_SIZE);
	while (rd != -1)
	{
		buff[rd] = 0;
		tmp = *line;
		*line = ft_strcjoin(*line, buff, '\n');
		ft_memdel(&tmp);
		if (!*line)
			return (-1);
		if (ft_strchr(buff, '\n'))
			return (__update_buff(buff));
		if (!rd && !**line)
			return (0);
		rd = read(STDIN_FILENO, buff, BUFFER_SIZE);
	}
	ft_memdel(line);
	return (-1);
}
