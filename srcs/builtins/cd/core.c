/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:18:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/06 11:05:36 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// chdir, access
#include <unistd.h>
// perror
#include <stdio.h>
//EXIT_SUCCESS
#include <stdlib.h>
#include "t_token_lst.h" // TODO token.h ou token_lst.h ?
#include "minishell.h"
#include "ft_io.h"
// TODO inclure les gestions de string de la libft

static unsigned int	__count_arg(t_token *args) // TODO eviter de compter les options
{
	unsigned int	nb_arg;

	nb_arg = 0;
	if (args == NULL)
		return (0);
	while (args->type == T_ARGUMENT)
	{
		args = args->next;
		nb_arg++;
	}
	return (nb_arg);
}

// CDPATH=path:path:path:path
static char	*__getcdpath(char *directory, bool *is_cdpath) //, t_env *env // TODO getcdpath()
{
	char	**cdpath;
	char	*tmp_path;
	char	*dest;
	int		i;

	i = 0;
	if (/*getenv("CDPATH") == NULL*/)
		return (directory);
	cdpath = ft_split(/*getenv("CDPATH")*/, ':'); // TODO inclure ft_split()
	while (cdpath[i])
	{
		if (cdpath[i][0] == '\0') // ou ft_strlen(cdpath[i]) == 0
			tmp_path = "./";
		else if (/*cdpath[i] ne fini pas par '/'*/) // TODO regarder si une string fini par un '/'
			tmp_path = ft_strjoin(cdpath[i], "/"); // TODO include ft_strjoin()
		else
			tmp_path = cdpath[i];
		dest = ft_strjoin(tmp_path, directory);
		free(tmp_path);
		if (access(dest, F_OK) == 0)
			break ;
		free(dest);
		i++;
	}
	free(cdpath);
	*is_cdpath = true;
	return (dest);
}

// je pars du principe que args pointe sur le premier argument
int	msh_cd(t_token *args) //, t_env *env // TODO traiter les options
{
	char			*directory;
	char			*curpath;
	char			*tmp_path;
	unsigned int	nb_arg;
	bool			is_cdpath;

	is_cdpath = false;
	nb_arg = __count_arg(args); 	// compte le nbr d'arguments
	if (nb_arg > 1)			  		// plus d'un argument est une erreur
	{
		ft_putendl_fd("cd: wrong number of arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	if (nb_arg == 0)				// s'il n'y a pas d'argument on recupere HOME
	{
		if (/*getenv("HOME") != NULL*/)
			directory = /*getenv("HOME")*/;
		else
		{
			ft_putendl_fd("cd: HOME not set", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
	}
	else
		directory = args->str;		// sinon on recupere le repertoire dans lequel on doit aller
	
	if (*directory != '/' && *directory != '.')// directory ne commence pas par '/' ni par '.' ni par '..'
		curpath = __getcdpath(directory, &is_cdpath);
	else
		curpath = directory;

	if (*curpath != '/') // TODO dans une fonction() // si curpath ne commence pas par un '/' on lui rajoute PWD au debut
	{
		if (/*PWD ne fini pas par '/'*/)
			tmp_path = ft_strjoin(/*getenv(PWD)*/, "/");
		else
			tmp_path = /*getenv(PWD)*/;
		curpath = ft_strjoin(tmp_path, curpath); // remplacer curpath dans ft_strjoin par un temporaire qu'on pourra free()
		free(tmp_path);
	}
	
	// clean de curpath (voir le google doc Minishell etape 8)

	if (chdir(curpath) == -1) 				// on change de working directory
	{
		perror("cd: chdir");
		return (EXIT_FAILURE);
	}

	if (/*getenv("PWD") != NULL*/) 			// on met a jour les variables d'environnement
	{
		// export OLDPWD=(getenv("PWD"))
	}
	// export PWD=(curpath)
	
	if (is_cdpath == true) 					// si on a utilise un path de CDPATH il faut faire un pwd()
		if (pwd() == EXIT_FAILURE)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
