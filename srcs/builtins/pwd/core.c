/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:19:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/30 17:54:23 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "e_ret.h"

int	pwd(void)
{
	char	*buf;

	buf = NULL;
	buf = getcwd(buf, 0);
	if (buf == NULL)
	{
		perror("pwd: getcwd");
		return (FAILURE);
	}
	if (printf("%s\n", buf) < 0)
	{
		perror("pwd: printf");
		free(buf);
		return (FAILURE);
	}
	free(buf);
	return (SUCCESS);
}