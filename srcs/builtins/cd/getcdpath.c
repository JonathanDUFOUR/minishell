/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcdpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:59:06 by majacque          #+#    #+#             */
/*   Updated: 2022/01/15 08:23:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_cd.h"

static char	*__error(char *directory, char **cdpath)
{
	free(directory);
	free(cdpath);
	return (NULL);
}

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
	if (tmp_path == NULL)
		return (NULL);
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
	if (env_lst_getone(env, "CDPATH") == NULL)
		return (directory);
	cdpath = ft_split(env_lst_getone(env, "CDPATH"), ':');
	if (cdpath == NULL)
		return (__error(directory, cdpath));
	while (cdpath[i])
	{
		dest = __getpath(cdpath[i++], directory);
		if (dest == NULL)
			return (__error(directory, cdpath));
		if (access(dest, F_OK) == 0)
			break ;
		ft_memdel(&dest);
	}
	free(cdpath);
	if (!dest)
		return (directory);
	free(directory);
	*is_cdpath = true;
	return (dest);
}
