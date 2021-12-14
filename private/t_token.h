/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:24:26 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/14 19:52:43 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TOKEN_H
# define T_TOKEN_H

# include "type/t_int.h"
# include "t_token_type.h"
# include "t_sed_lst.h"
# include "t_env_lst.h"

typedef struct s_token	t_token;

struct	s_token
{
	char const		*str;
	t_token_type	type;
	t_sed_lst		seds;
	t_token			*next;
	t_token			*prev;
};

int		error_option(const char *str, t_token *args)
		__attribute__((nonnull));
int		token_expand(t_token *const node, t_env_lst *const env)
		__attribute__((nonnull));
int		token_merge(t_token *const node)
		__attribute__((nonnull));
int		token_sed(t_token *const node)
		__attribute__((nonnull));

void	token_print(t_token const *const node)
		__attribute__((nonnull));

t_uint	count_args(t_token *args);

t_token	*token_get(char const *line)
		__attribute__((nonnull));

t_token	*token_new(char const *str, t_token_type const type,
			t_sed_lst const expands);

char	**tokens_to_aa(t_token *command, size_t n)
		__attribute__((nonnull));

#endif
