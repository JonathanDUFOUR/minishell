/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcdpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:59:06 by majacque          #+#    #+#             */
/*   Updated: 2021/12/10 18:16:58 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_cd.h"

// SECURE toutes les allocations

static char	*__getpath(char *cdpath, char *directory)
{
	char	*tmp_path;
	char	*dest;

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

char	*__getcdpath(t_env_lst *env, char *directory, bool *is_cdpath)
{
	char	**cdpath;
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
	free(cdpath);
	if (!dest)
		return (directory);
	free(directory);
	*is_cdpath = true;
	return (dest);
}
