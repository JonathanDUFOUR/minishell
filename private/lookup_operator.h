/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_operator.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 02:35:01 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 00:32:00 by jodufour         ###   ########.fr       */
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
{">", T_REDIRECTOUT, T_FILE},
{">>", T_REDIRECTOUT, T_FILE},
{"<", T_REDIRECTIN, T_FILE},
{"<<", T_REDIRECTIN, T_DELIMITER},
{"|", T_PIPE, T_WORD},
{0}
};

#endif
