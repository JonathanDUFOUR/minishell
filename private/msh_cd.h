/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:20:12 by majacque          #+#    #+#             */
/*   Updated: 2022/01/20 18:20:12 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_CD_H
# define MSH_CD_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include "ft_io.h"
# include "ft_string.h"
# include "minishell.h"
# include "lookup_builtin.h"

bool	__is_ending_slash(const char *str)
		__attribute__((nonnull));
bool	__isdirectory(const char *pathname)
		__attribute__((nonnull));
int		__error_cd(const char *str)
		__attribute__((nonnull));
int		__error_chdir(const char *str, char *curpath)
		__attribute__((nonnull (1)));

char	*__getcdpath(t_env_lst *const env, char *directory,
			bool *const is_cdpath)
		__attribute__((nonnull));
char	*__cleanpath(char *curpath);
char	*__error_getpwd(char *curpath);

#endif
