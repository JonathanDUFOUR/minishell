/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:19:40 by majacque          #+#    #+#             */
/*   Updated: 2022/01/18 16:05:38 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_cd.h"

bool	__is_ending_slash(const char *str)
{
	str = &str[ft_strlen(str) - 1];
	if (*str != '/')
		return (false);
	return (true);
}

bool	__isdirectory(const char *pathname)
{
	struct stat	statbuf;

	if (stat(pathname, &statbuf))
		return (false);
	if (S_ISDIR(statbuf.st_mode))
		return (true);
	else
		return (false);
}

int	__error_cd(const char *str)
{
	ft_putstr_fd("cd: '", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putendl_fd("': Not a directory", STDERR_FILENO);
	ft_memdel(&str);
	return (EXIT_FAILURE);
}
