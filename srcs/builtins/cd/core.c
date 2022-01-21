/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:18:42 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/21 01:25:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_cd.h"

static char	*__getdirectory(t_env_lst *env, t_token *args, t_uint nb_arg)
{
	char	*directory;

	if (nb_arg == 0)
	{
		if (env_lst_getone(env, "HOME") != NULL)
		{
			directory = ft_strdup(env_lst_getone(env, "HOME"));
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
		directory = ft_strdup(args->next->str);
		if (directory == NULL)
			return (NULL);
	}
	return (directory);
}

static char	*__getpwd(t_env_lst *env, char *curpath)
{
	char	*pwd_path;
	char	*tmp_path;

	if (*curpath != '/')
	{
		if (!env_lst_getone(env, "PWD"))
		{
			tmp_path = getcwd(NULL, 0);
			if (!tmp_path)
				return (__error_getpwd(curpath));
			pwd_path = ft_strjoin(tmp_path, "/");
			ft_memdel(&tmp_path);
		}
		else if (__is_ending_slash(env_lst_getone(env, "PWD")) == false)
			pwd_path = ft_strjoin(env_lst_getone(env, "PWD"), "/");
		else
			pwd_path = ft_strdup(env_lst_getone(env, "PWD"));
		if (pwd_path == NULL)
			return (__error_getpwd(curpath));
		tmp_path = curpath;
		curpath = ft_strjoin(pwd_path, tmp_path);
		free(pwd_path);
		free(tmp_path);
	}
	return (curpath);
}

static int	__updatepwd(t_env_lst *env, char *curpath)
{
	char	*tmp_path;

	tmp_path = &curpath[ft_strlen(curpath) - 1];
	if (*tmp_path == '.')
		*(tmp_path - 1) = '\0';
	if (env_lst_getone(env, "PWD") != NULL)
	{
		tmp_path = ft_strjoin("OLDPWD=", env_lst_getone(env, "PWD"));
		if (tmp_path == NULL)
			return (EXIT_FAILURE);
		if (env_lst_putone(env, tmp_path) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		free(tmp_path);
	}
	else
		env_lst_unset(env, "OLDPWD");
	tmp_path = ft_strjoin("PWD=", curpath);
	if (tmp_path == NULL)
		return (EXIT_FAILURE);
	if (env_lst_putone(env, tmp_path) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free(tmp_path);
	return (EXIT_SUCCESS);
}

static char	*__setcurpath(t_env_lst *env, t_token *args, bool *is_cdpath)
{
	char	*directory;
	char	*curpath;

	directory = __getdirectory(env, args, token_args_count(args));
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

int	msh_cd(t_env_lst *const env, t_token *const token)
{
	char	*curpath;
	bool	is_cdpath;

	if (token->next && token->next->type == T_OPTION)
		return (error_option("cd: ", token->next->str));
	if (token_args_count(token) != 1)
		return (error_argument("cd: wrong number of arguments"));
	curpath = __setcurpath(env, token, &is_cdpath);
	if (curpath == NULL)
		return (EXIT_FAILURE);
	if (chdir(curpath) == -1)
		return (__error_chdir(token->next->str, curpath));
	if (__updatepwd(env, curpath) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free(curpath);
	if (is_cdpath == true)
		if (msh_pwd(env, NULL) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
