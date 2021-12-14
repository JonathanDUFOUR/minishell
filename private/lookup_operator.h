/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_operator.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 02:35:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/14 03:34:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_OPERATOR_H
# define LOOKUP_OPERATOR_H

# include "t_token_type.h"

# ifndef OPERATOR_CHARS
#  define OPERATOR_CHARS	"<>|"
# endif

typedef struct s_operator	t_operator;

struct s_operator
{
	char const			*str;
	t_token_type const	type;
	t_token_type const	next;
};

static t_operator const		g_operator[] = {
{">", T_REDIRECT, T_FILE},
{"<", T_REDIRECT, T_FILE},
{">>", T_REDIRECT, T_FILE},
{"<<", T_REDIRECT, T_DELIMITER},
{"|", T_PIPE, T_WORD},
{0}
};

#endif
