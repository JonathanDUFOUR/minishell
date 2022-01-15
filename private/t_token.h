/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:24:26 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 10:24:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TOKEN_H
# define T_TOKEN_H

# include "type/t_int.h"
# include "t_env_lst.h"
# include "t_sed_lst.h"
# include "t_token_type.h"

typedef struct s_token	t_token;

struct	s_token
{
	char const		*str;
	t_token_type	type;
	t_sed_lst		seds;
	t_token			*next;
	t_token			*prev;
};

int		token_expand(t_token *const node, t_env_lst *const env)
		__attribute__((nonnull));
int		token_here_doc(t_token *const node, t_env_lst *const env,
			char const *program)
		__attribute__((nonnull));
int		token_merge(t_token *const node)
		__attribute__((nonnull));
int		token_sed(t_token *const node)
		__attribute__((nonnull));

void	token_clear(t_token *const node)
		__attribute__((nonnull));
void	token_delone(t_token *node)
		__attribute__((nonnull));
void	token_print(t_token const *const node)
		__attribute__((nonnull));

char	*token_last_here_doc_str(t_token const *const node)
		__attribute__((nonnull));

char	**token_get_cmd_opt_arg(t_token const *const node)
		__attribute__((nonnull));

t_uint	token_args_count(t_token const *args);

t_token	*token_get(char const *line)
		__attribute__((nonnull));

t_token	*token_new(char const *str, t_token_type const type,
			t_sed_lst const seds);

#endif
