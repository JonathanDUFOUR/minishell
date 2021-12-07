/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:18:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/07 18:25:57 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_cd.h"

// SECURE toutes les allocations

static char	*__getdirectory(t_env_lst *env, char *args_str, int nb_arg)
{
	if (nb_arg == 0)
	{
		if (get_env("HOME", env) != NULL)
			return (ft_strdup(get_env("HOME", env)));
		else
		{
			ft_putendl_fd("cd: HOME not set", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
	}
	else
		return (ft_strdup(args_str));
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

	if (get_env("PWD", env) != NULL)
	{
		tmp_path = ft_strjoin("OLDPWD=", get_env("PWD", env));
		put_env(tmp_path, env);
		free(tmp_path);
	}
	tmp_path = ft_strjoin("PWD=", curpath);
	put_env(tmp_path, env);
	free(tmp_path);
	return (EXIT_SUCCESS);
}

static char	*__cleanpath(char *curpath)
{
	/*
	 * a. un "./" doit etre supprime s'il y a un mot apres
	 * b. pour chaque "../", s'il y a un mot avant et que c'est ni root ni "../" alors :
	 * 		i. si l'element d'avant ne fait pas reference a un repertoire --> erreur
	 * 		ii. l'element precedent, tous les '/' qui le separe de "..",
	 * 			".." et tous les '/' qui le separe de l'element d'apres (s'il y en a un) doivent etre supprime
	 * c. - supprimer tous les trailing '/' qui ne sont pas des leading '/'
	 * 	  - remplacer tous les non-leading '/' consecutifs par un seul '/'
	 * 	  - remplacer 3 ou plus leading '/' par un seul
	 * 	  si apres ca curpath est null, il ne faut pas aller plus loin
	 * 
	 * leading slash --> /dir/dir/dir/ <-- trailing slash
	 */
}

int	msh_cd(t_env_lst *env, t_token *args)
{
	char			*directory;
	char			*curpath;
	unsigned int	nb_arg;
	bool			is_cdpath;

	// Gestion d'erreurs
	if (args->type == T_OPTION)
		return (error_option("cd: ", args));
	nb_arg = count_args(args);
	if (nb_arg > 1)
	{
		ft_putendl_fd("cd: wrong number of arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	// S'il n'y a pas d'argument on essaye de recuperer HOME sinon on recupere l'argument
	directory = __getdirectory(env, args->str, nb_arg); // SECURE __getdirectory()
	
	// Si directory ne commence pas par '/' ni par '.' ni par '..' on essaye de recuperer un path de CDPATH
	is_cdpath = false;
	if (*directory != '/' && *directory != '.')
		curpath = __getcdpath(env, directory, &is_cdpath);
	else
		curpath = directory;

	// Si curpath ne commence pas par un '/' on lui rajoute PWD au debut
	curpath = __getpwd(env, curpath); // SECURE __getpwd()

	// TODO clean de curpath (voir le google doc Minishell etape 8)

	// On change de working directory
	if (chdir(curpath) == -1)
		return (EXIT_FAILURE);

	// On met a jour les variables d'environnement
	__updatepwd(env, curpath); // SECURE __updatepwd()

	// Si on a utilise un path de CDPATH il faut faire un pwd()
	if (is_cdpath == true)
		if (msh_pwd(NULL) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
