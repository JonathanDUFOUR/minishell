/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/14 19:49:51 by majacque         ###   ########.fr       */
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

int		set_sigint_handle(void);
int		set_sigquit_handle(void);

void	free_tab2d(char **tab)
		__attribute__((nonnull));

size_t	namelen(char const *str)
		__attribute__((nonnull));

char	*msh_str3join(char const *s1, char const *s2, char const *s3)
		__attribute__((nonnull));

#endif
