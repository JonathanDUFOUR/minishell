/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:20:12 by majacque          #+#    #+#             */
/*   Updated: 2022/01/15 08:02:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_CD_H
# define MSH_CD_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "minishell.h"
# include "lookup_builtin.h"
# include "ft_io.h"
# include "ft_string.h"

bool	__is_ending_slash(const char *str)
		__attribute__((nonnull));
bool	__isdirectory(const char *pathname)
		__attribute__((nonnull));

char	*__getcdpath(t_env_lst *const env, char *directory,
			bool *const is_cdpath)
		__attribute__((nonnull));
char	*__cleanpath(char *curpath);

#endif
