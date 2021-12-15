/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token_lst.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:26:41 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/15 21:55:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TOKEN_LST_H
# define T_TOKEN_LST_H

# include <stddef.h>
# include "t_token.h"
# include "t_env_lst.h"

typedef struct s_token_lst	t_token_lst;

struct s_token_lst
{
	t_token	*head;
	t_token	*tail;
	size_t	size;
};

int		token_lst_expand(t_token_lst *const tokens, t_env_lst *const env)
		__attribute__((nonnull));
int		token_lst_get(t_token_lst *const tokens, char const *line,
			t_env_lst *const env)
		__attribute__((nonnull));
int		token_lst_merge(t_token_lst *const tokens)
		__attribute__((nonnull));
int		token_lst_sed(t_token_lst *const tokens)
		__attribute__((nonnull));
int		token_lst_split(t_token_lst *const tokens)
		__attribute__((nonnull));
int		token_lst_syntax_check(t_token_lst *const tokens, char const *program)
		__attribute__((nonnull));

void	token_lst_clear(t_token_lst *const tokens)
		__attribute__((nonnull));
void	token_lst_delone(t_token_lst *const tokens, t_token *const node)
		__attribute__((nonnull));
void	token_lst_print(t_token_lst const *const tokens)
		__attribute__((nonnull));
void	token_lst_push_back(t_token_lst *const tokens, t_token *const node)
		__attribute__((nonnull));
void	token_lst_remove_useless(t_token_lst *const tokens)
		__attribute__((nonnull));
void	token_lst_which_word(t_token_lst *const tokens)
		__attribute__((nonnull));
void	token_lst_word_or_operator(t_token_lst *const tokens)
		__attribute__((nonnull));

#endif
