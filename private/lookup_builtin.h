/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_builtin.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:05:46 by majacque          #+#    #+#             */
/*   Updated: 2022/01/15 06:11:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_BUILTIN_H
# define LOOKUP_BUILTIN_H

# include "minishell.h"

typedef struct s_builtin	t_builtin;
typedef int					(*t_fct)(t_env_lst *const, t_token *const);

struct s_builtin
{
	char const	*name;
	t_fct const	fct;
};

int		msh_cd(t_env_lst *const env, t_token *const token)
		__attribute__((nonnull));
int		msh_echo(t_env_lst *env, t_token *const token)
		__attribute__((nonnull));
int		msh_env(t_env_lst *const env, t_token *const token)
		__attribute__((nonnull));
int		msh_exit(t_env_lst *const env, t_token *const token)
		__attribute__((nonnull (1)));
int		msh_export(t_env_lst *const env, t_token *const token)
		__attribute__((nonnull));
int		msh_pwd(t_env_lst *const env, t_token *const token)
		__attribute__((nonnull (1)));
int		msh_unset(t_env_lst *const env, t_token *const token)
		__attribute__((nonnull));

static t_builtin const		g_builtin[] = {
{"cd", msh_cd},
{"echo", msh_echo},
{"exit", msh_exit},
{"env", msh_env},
{"export", msh_export},
{"pwd", msh_pwd},
{"unset", msh_unset},
{0}
};

#endif
