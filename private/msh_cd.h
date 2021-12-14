/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:20:12 by majacque          #+#    #+#             */
/*   Updated: 2021/12/14 19:43:05 by majacque         ###   ########.fr       */
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
# include "ft_mem.h"
# include "ft_string.h"

bool	__is_ending_slash(const char *str);
bool	__isdirectory(const char *pathname);

char	*__getcdpath(t_env_lst *env, char *directory, bool *is_cdpath);
char	*__cleanpath(char *curpath);

#endif