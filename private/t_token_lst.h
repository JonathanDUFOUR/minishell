/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token_lst.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:26:41 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/02 18:37:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TOKEN_LST_H
# define T_TOKEN_LST_H

# include <stddef.h>
# include "t_token.h"

typedef struct s_token_lst	t_token_lst;

struct s_token_lst
{
	t_token	*head;
	t_token	*tail;
	size_t	size;
};

int		token_lst_get(t_token_lst *const tokens, char const *line)
		__attribute__((nonnull));

void	token_lst_clear(t_token_lst *const tokens)
		__attribute__((nonnull));
void	token_lst_delone(t_token_lst *const tokens, t_token *const node)
		__attribute__((nonnull));
void	token_lst_print(t_token_lst *const tokens)
		__attribute__((nonnull));
void	token_lst_push_back(t_token_lst *const tokens, t_token *const node)
		__attribute__((nonnull));
void	token_lst_type_define(t_token_lst *const tokens)
		__attribute__((nonnull));

#endif
