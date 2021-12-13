/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:57:06 by majacque          #+#    #+#             */
/*   Updated: 2021/12/13 17:41:47 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_cd.h"

static void	__del_consecutive_slash(char *curpath)
{
	char	*src;

	curpath++;
	src = curpath;
	while (*src && *src == '/')
		src++;
	curpath = ft_memmove(curpath, src, (ft_strlen(src) + 1));
}

static void	__cleanslash(char *curpath)
{
	if (*curpath == '/' && *(curpath + 1) == '/' && *(curpath + 2) != '/')
		curpath += 2;
	while (*curpath)
	{
		if (*curpath == '/' && *(curpath + 1) == '/')
			__del_consecutive_slash(curpath);
		curpath++;
	}
	curpath--;
	if (*curpath == '/')
		*curpath = '\0';
}

static int	__del_name_dotdot(char *curpath, char *tmp_curpath, char *cursor)
{
	char	*tmp;

	tmp = ft_strndup(curpath, (cursor - curpath) + 1);
	if (tmp == NULL)
		return (EXIT_FAILURE);
	if (__isdirectory(tmp) == false)
	{
		ft_putstr_fd("cd: '", STDERR_FILENO);
		ft_putstr_fd(tmp, STDERR_FILENO);
		ft_putendl_fd("': not a directory", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ft_memdel(&tmp);
	tmp = cursor;
	if (tmp != curpath)
		tmp--;
	while (tmp != tmp_curpath && *tmp != '/')
		tmp--;
	if (*tmp == '/')
		tmp++;
	ft_memmove(tmp, cursor + 4, ft_strlen(cursor + 4) + 1);
	return (EXIT_SUCCESS);
}

static int	__del_dotdot(char *curpath)
{
	char	*tmp_curpath;
	char	*cursor;

	tmp_curpath = curpath;
	cursor = ft_strstr(tmp_curpath, "/../");
	while (cursor)
	{
		if (cursor != curpath && *(cursor - 1) == '.' && *(cursor - 2) == '.')
			tmp_curpath = cursor + 1;
		else
			if (__del_name_dotdot(curpath, tmp_curpath, cursor) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		cursor = ft_strstr(tmp_curpath, "/../");
	}
	return (EXIT_SUCCESS);
}

char	*__cleanpath(char *curpath)
{
	char	*cursor;
	char	*tmp_curpath;

	tmp_curpath = curpath;
	cursor = ft_strstr(tmp_curpath, "./");
	while (cursor)
	{
		if (*(cursor + 2) == '\0')
			break ;
		if (cursor != curpath && *(cursor - 1) != '.')
			cursor = ft_memmove(cursor, cursor + 2, ft_strlen(cursor + 2) + 1);
		else
			tmp_curpath = cursor + 2;
		cursor = ft_strstr(tmp_curpath, "./");
	}
	if (__del_dotdot(curpath) == EXIT_FAILURE)
	{
		free(curpath);
		return (NULL);
	}
	__cleanslash(curpath);
	return (curpath);
}
