/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:24:26 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/03 19:21:36 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TOKEN_H
# define T_TOKEN_H

typedef struct s_token	t_token;

struct	s_token
{
	char const	*str;
	int const	type;
	t_token		*next;
	t_token		*prev;
};

enum	e_type
{
	T_WORD,
	T_FILE,
	T_OPTION,
	T_COMMAND,
	T_ARGUMENT,
	T_OPERATOR,
	T_PIPE,
};

int	error_option(const char *str, t_token *args)__attribute__((nonnull));

#endif
