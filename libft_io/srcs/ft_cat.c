/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 06:21:42 by jdufour           #+#    #+#             */
/*   Updated: 2021/11/15 20:06:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_io.h"

void	ft_cat(char const **files)
{
	char	output[BUFF_SIZE];
	ssize_t	rd;
	int		fd;

	if (!files)
		return ;
	while (*files)
	{
		fd = open(*files++, O_RDONLY);
		if (fd < 0)
			continue ;
		rd = read(fd, &output, BUFF_SIZE);
		while (rd > 0)
		{
			write(1, &output, rd);
			rd = read(fd, &output, BUFF_SIZE);
		}
		close(fd);
	}
}
