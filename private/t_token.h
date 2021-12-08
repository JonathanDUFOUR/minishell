/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:24:26 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/08 15:48:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TOKEN_H
# define T_TOKEN_H

# include "t_type.h"
# include "t_env_lst.h"

typedef struct s_token	t_token;

struct	s_token
{
	char const	*str;
	t_type		type;
	t_token		*next;
	t_token		*prev;
};

unsigned int	count_args(t_token *args);

int				error_option(const char *str, t_token *args)
				__attribute__((nonnull));
int				token_expand(t_token *const node, t_env_lst *const env)
				__attribute__((nonnull));

void			token_print(t_token const *const node)
				__attribute__((nonnull));

t_token			*token_get(char const *line)
				__attribute__((nonnull));

t_token			*token_new(char const *str, t_type const type)
				__attribute__((nonnull (1)));

#endif
