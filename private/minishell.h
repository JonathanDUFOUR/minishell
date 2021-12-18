/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 18:59:12 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "t_token_lst.h"
# include "t_env_lst.h"
# include <stddef.h>
# include <stdlib.h>

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

typedef int	t_tube[2];

int		pipeline(t_token_lst *tokens, t_env_lst *env)
		__attribute__((nonnull));
int		setup_fork(t_token *token, t_env_lst *env, t_tube in, t_tube out)
		__attribute__((nonnull));
int		exec_cmd(t_token *token, t_env_lst *env, t_tube in, t_tube out)
		__attribute__((nonnull));

int		set_sigint_handle(void);
int		set_sigquit_handle(void);

void	free_tab2d(char **tab)
		__attribute__((nonnull));

size_t	namelen(char const *str)
		__attribute__((nonnull));

char	*msh_str3join(char const *s1, char const *s2, char const *s3)
		__attribute__((nonnull));

#endif
