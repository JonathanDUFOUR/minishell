/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/23 10:23:47 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "t_token_lst.h"
# include "t_env_lst.h"
# include <stdlib.h>

# ifndef PROMPT
#  define PROMPT "minishell$> "
# endif

# ifndef HERE_DOC_PROMPT
#  define HERE_DOC_PROMPT "> "
# endif

# ifndef VAR_CHARS
#  define VAR_CHARS "\
abcdefghijklmnopqrstuvwxyz\
ABCDEFGHIJKLMNOPQRSTUVWXYZ\
0123456789\
_"
# endif

# ifndef VAR_FIRST_CHARS
#  define VAR_FIRST_CHARS "\
abcdefghijklmnopqrstuvwxyz\
ABCDEFGHIJKLMNOPQRSTUVWXYZ\
_"
# endif

int		pipeline(t_token_lst *tokens, t_env_lst *env)
		__attribute__((nonnull));

int		sigint_default(void);
int		sigint_here_doc(void);
int		sigquit_default(void);
int		sigterm_default(void);

size_t	namelen(char const *str)
		__attribute__((nonnull));

char	*msh_str3join(char const *s1, char const *s2, char const *s3)
		__attribute__((nonnull));

#endif
