/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:20:12 by majacque          #+#    #+#             */
/*   Updated: 2021/12/07 17:25:39 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_CD_H
# define MSH_CD_H

// chdir, access
# include <unistd.h>
// perror
# include <stdio.h>
//EXIT_SUCCESS
# include <stdlib.h>
# include "t_token.h"
# include "minishell.h"
# include "ft_io.h"
# include "ft_mem.h"
# include "ft_string.h"

bool	__is_ending_slash(const char *str);

char	*__getcdpath(t_env_lst *env, char *directory, bool *is_cdpath);

#endif