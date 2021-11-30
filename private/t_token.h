/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:24:26 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/30 11:25:52 by jodufour         ###   ########.fr       */
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
	WORD,
	FILE,
	OPTION,
	COMMAND,
	ARGUMENT,
	OPERATOR,
	PIPE,
};

#endif
