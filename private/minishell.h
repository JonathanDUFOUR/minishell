/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/14 18:46:38 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "t_token_lst.h"
# include "t_env_lst.h"
# include "g_exit_status.h"
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

int		msh_cd(t_env_lst *env, t_token *args)
		__attribute__((nonnull (1)));
int		msh_env(t_env_lst *env, t_token *args)
		__attribute__((nonnull (1)));
void	msh_exit(t_env_lst *env, t_token_lst *tokens)
		__attribute__((nonnull));
int		msh_export(t_env_lst *env, t_token *args)
		__attribute__((nonnull (1)));
int		msh_pwd(t_env_lst *env, t_token *args)
		__attribute__((nonnull (1)));
int		msh_unset(t_env_lst *env, t_token *args)
		__attribute__((nonnull (1)));

int		set_sigint_handle(void);
int		set_sigquit_handle(void);

void	msh_echo(t_token *args);
void	free_tab2d(char **tab)
		__attribute__((nonnull));

size_t	namelen(char const *str)
		__attribute__((nonnull));

char	*msh_str3join(char const *s1, char const *s2, char const *s3)
		__attribute__((nonnull));

#endif
