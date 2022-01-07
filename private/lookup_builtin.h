/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_builtin.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:05:46 by majacque          #+#    #+#             */
/*   Updated: 2022/01/06 16:47:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_BUILTIN_H
# define LOOKUP_BUILTIN_H

# include "minishell.h"

typedef struct s_builtin	t_builtin;

struct s_builtin
{
	char const	*name;
	int			(*f)(t_env_lst *, t_token *);
};

int		msh_cd(t_env_lst *env, t_token *args)
		__attribute__((nonnull (1)));
int		msh_echo(__attribute__((unused))t_env_lst *env, t_token *args);
int		msh_env(t_env_lst *env, t_token *args)
		__attribute__((nonnull (1)));
int		msh_exit(t_env_lst *env, t_token *args)
		__attribute__((nonnull));
int		msh_export(t_env_lst *env, t_token *args)
		__attribute__((nonnull (1)));
int		msh_pwd(__attribute__((unused))t_env_lst *env, t_token *args);
int		msh_unset(t_env_lst *env, t_token *args)
		__attribute__((nonnull (1)));

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
