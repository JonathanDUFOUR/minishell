/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:01 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 17:28:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include "t_token_lst.h"

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

int		error_argument(char const *str)
		__attribute__((nonnull));
int		error_option(char const *str, char const *opt)
		__attribute__((nonnull));
int		sigall_default(void);
int		sigall_mute(void);
int		sigall_reset(void);
int		sigint_default(void);
int		sigint_here_doc(void);
int		sigint_mute(void);
int		sigint_reset(void);
int		sigpipe_default(void);
int		sigpipe_mute(void);
int		sigpipe_reset(void);
int		sigquit_default(void);
int		sigquit_mute(void);
int		sigquit_reset(void);
int		sigterm_default(void);
int		sigterm_mute(void);
int		sigterm_reset(void);
int		usage_err(char const *program)
		__attribute__((nonnull));

char	*msh_str3join(char const *s1, char const *s2, char const *s3)
		__attribute__((nonnull));
char	*prompt_get(t_env_lst *const env, char const *program)
		__attribute__((nonnull));

size_t	namelen(char const *str)
		__attribute__((nonnull));

#endif
