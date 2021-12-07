/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:19:40 by majacque          #+#    #+#             */
/*   Updated: 2021/12/07 17:37:08 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_cd.h"

// SECURE toutes les allocations

static void	__free_tab_string(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	*__getpath(char *cdpath, char *directory)
{
	char *tmp_path;
	char *dest;

	if (ft_strlen(cdpath) == 0)
		tmp_path = ft_strdup("./");
	else if (__is_ending_slash(cdpath) == false)
		tmp_path = ft_strjoin(cdpath, "/");
	else
		tmp_path = ft_strdup(cdpath);
	dest = ft_strjoin(tmp_path, directory);
	free(tmp_path);
	return (dest);
}

// CDPATH=path:path:path:path
char	*__getcdpath(t_env_lst *env, char *directory, bool *is_cdpath)
{
	char	**cdpath;
	char	*tmp_path;
	char	*dest;
	int		i;

	i = 0;
	if (get_env("CDPATH", env) == NULL)
		return (directory);
	cdpath = ft_split(get_env("CDPATH", env), ':');
	while (cdpath[i])
	{
		dest = __getpath(cdpath[i], directory);
		if (access(dest, F_OK) == 0)
			break ;
		ft_memdel(&dest);
		i++;
	}
	__free_tab_string(cdpath);
	if (!dest)
		return (directory);
	free(directory);
	*is_cdpath = true;
	return (dest);
}

bool	__is_ending_slash(const char *str)
{
	str = ft_strlen(str) - 1;
	if (*str != '/')
		return (false);
	return (true);
}
