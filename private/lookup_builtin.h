/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_builtin.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:05:46 by majacque          #+#    #+#             */
/*   Updated: 2021/12/14 19:43:54 by majacque         ###   ########.fr       */
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
void	msh_exit(t_env_lst *env, t_token_lst *tokens)
		__attribute__((nonnull));
int		msh_export(t_env_lst *env, t_token *args)
		__attribute__((nonnull (1)));
int		msh_pwd(__attribute__((unused))t_env_lst *env, t_token *args);
int		msh_unset(t_env_lst *env, t_token *args)
		__attribute__((nonnull (1)));

static t_builtin const		g_builtin[] = {
{"cd", msh_cd},
{"echo", msh_echo},
{"env", msh_env},
{"export", msh_export},
{"pwd", msh_pwd},
{"unset", msh_unset},
{0}
};
// FIX il faudra faire une exeption pour exit 
// ou faire un token_lst_clear qui prend en parametre un 't_token *'

#endif
