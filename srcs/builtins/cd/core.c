/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:18:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/14 18:49:13 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_cd.h"

static char	*__getdirectory(t_env_lst *env, t_token *args, int nb_arg)
{
	char	*directory;

	if (nb_arg == 0)
	{
		if (get_env("HOME", env) != NULL)
		{
			directory = ft_strdup(get_env("HOME", env));
			if (directory == NULL)
				return (NULL);
		}
		else
		{
			ft_putendl_fd("cd: HOME not set", STDERR_FILENO);
			return (NULL);
		}
	}
	else
	{
		directory = ft_strdup(args->str);
		if (directory == NULL)
			return (NULL);
	}
	return (directory);
}

static char	*__getpwd(t_env_lst *env, char *curpath)
{
	char	*pwd_path;
	char	*tmp_path;
	char	*dest;

	dest = curpath;
	if (*dest != '/')
	{
		if (__is_ending_slash(get_env("PWD", env)) == false)
			pwd_path = ft_strjoin(get_env("PWD", env), "/");
		else
			pwd_path = ft_strdup(get_env("PWD", env));
		if (pwd_path == NULL)
			return (NULL);
		tmp_path = dest;
		dest = ft_strjoin(pwd_path, tmp_path);
		free(pwd_path);
		free(tmp_path);
	}
	return (dest);
}

static int	__updatepwd(t_env_lst *env, char *curpath)
{
	char	*tmp_path;

	tmp_path = &curpath[ft_strlen(curpath) - 1];
	if (*tmp_path == '.')
		*(tmp_path - 1) = '\0';
	if (get_env("PWD", env) != NULL)
	{
		tmp_path = ft_strjoin("OLDPWD=", get_env("PWD", env));
		if (tmp_path == NULL)
			return (EXIT_FAILURE);
		if (put_env(tmp_path, env) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		free(tmp_path);
	}
	tmp_path = ft_strjoin("PWD=", curpath);
	if (tmp_path == NULL)
		return (EXIT_FAILURE);
	if (put_env(tmp_path, env) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free(tmp_path);
	return (EXIT_SUCCESS);
}

static char	*__setcurpath(t_env_lst *env, t_token *args, bool *is_cdpath)
{
	char	*directory;
	char	*curpath;

	directory = __getdirectory(env, args, count_args(args));
	if (directory == NULL)
		return (NULL);
	*is_cdpath = false;
	if (*directory != '/' && *directory != '.')
		curpath = __getcdpath(env, directory, is_cdpath);
	else
		curpath = directory;
	if (curpath == NULL)
		return (NULL);
	curpath = __getpwd(env, curpath);
	if (curpath == NULL)
		return (NULL);
	curpath = __cleanpath(curpath);
	if (curpath == NULL)
		return (NULL);
	return (curpath);
}

int	msh_cd(t_env_lst *env, t_token *args)
{
	char			*curpath;
	bool			is_cdpath;

	if (args && args->type == T_OPTION)
		return (error_option("cd: ", args));
	if (count_args(args) > 1)
	{
		ft_putendl_fd("cd: wrong number of arguments", STDERR_FILENO);
		return (EXIT_SUCCESS);
	}
	curpath = __setcurpath(env, args, &is_cdpath);
	if (curpath == NULL)
		return (EXIT_FAILURE);
	if (chdir(curpath) == -1)
	{
		perror("cd");
		return (EXIT_FAILURE);
	}
	if (__updatepwd(env, curpath) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free(curpath);
	if (is_cdpath == true)
		if (msh_pwd(env, NULL) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
