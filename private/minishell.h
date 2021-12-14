/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/13 17:00:10 by jodufour         ###   ########.fr       */
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

# ifndef VAR_CHARS
#  define VAR_CHARS	"\
abcdefghijklmnopqrstuvwxyz\
ABCDEFGHIJKLMNOPQRSTUVWXYZ\
0123456789\
_"
# endif

int		msh_env(t_env_lst *const env, t_token *args)
		__attribute__((nonnull (1)));
int		msh_export(t_env_lst *const env, t_token *args)
		__attribute__((nonnull (1)));
int		msh_pwd(t_token *args);
int		msh_unset(t_env_lst *const env, t_token *args)
		__attribute__((nonnull (1)));
int		set_sigint_handle(void);
int		set_sigquit_handle(void);

void	msh_echo(t_token *args);

size_t	namelen(char const *str)
		__attribute__((nonnull));

#endif
