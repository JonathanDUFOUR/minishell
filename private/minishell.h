/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/07 14:21:10 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "t_token_lst.h"
# include "t_env_lst.h"
# include <stddef.h>

# ifndef PROMPT
#  define PROMPT	"$> "
# endif

int		append_expand(char **const str, char const **const ptr)
		__attribute__((nonnull));
int		append_literal(char **const str, char const **const ptr)
		__attribute__((nonnull));
int		msh_env(t_env_lst *data, t_token *args)
		__attribute__((nonnull (1)));
int		msh_export(t_env_lst *data, t_token *args)
		__attribute__((nonnull (1)));
int		msh_pwd(t_token *args);
int		msh_unset(t_env_lst *data, t_token *args)
		__attribute__((nonnull (1)));

void	msh_echo(t_token *args);

size_t	varlen(char const *str)
		__attribute__((nonnull));

#endif
