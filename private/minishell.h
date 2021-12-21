/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/21 06:20:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "t_token_lst.h"
# include "t_env_lst.h"
# include <stddef.h>
# include <stdlib.h>

# ifndef PROMPT
#  define PROMPT	"minishell$> "
# endif

# ifndef HERE_DOC_PROMPT
#  define HERE_DOC_PROMPT	"> "
# endif

# ifndef VAR_CHARS
#  define VAR_CHARS	"\
abcdefghijklmnopqrstuvwxyz\
ABCDEFGHIJKLMNOPQRSTUVWXYZ\
0123456789\
_"
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	65536
# endif

typedef int	t_tube[2];

int		exec_cmd(t_token *token, t_env_lst *env, t_tube in, t_tube out)
		__attribute__((nonnull));
int		pipeline(t_token_lst *tokens, t_env_lst *env)
		__attribute__((nonnull));
int		setup_fork(t_token *token, t_env_lst *env, t_tube in, t_tube out)
		__attribute__((nonnull));
int		setup_sigint_handle(void);
int		setup_sigquit_handle(void);

size_t	namelen(char const *str)
		__attribute__((nonnull));

char	*msh_str3join(char const *s1, char const *s2, char const *s3)
		__attribute__((nonnull));

#endif
