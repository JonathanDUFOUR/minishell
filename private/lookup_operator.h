/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_operator.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 02:35:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/04 17:17:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_OPERATOR_H
# define LOOKUP_OPERATOR_H

# include "t_type.h"

# ifndef OPERATOR_CHARS
#  define OPERATOR_CHARS	"<>|"
# endif

typedef struct s_operator	t_operator;

struct s_operator
{
	char const		*str;
	t_type const	type;
	t_type const	next;
};

static t_operator const		g_operator[] = {
{">", T_REDIRECT, T_FILE},
{"<", T_REDIRECT, T_FILE},
{">>", T_REDIRECT, T_FILE},
{"<<", T_REDIRECT, T_DELIMITER},
{"|", T_PIPE, T_COMMAND},
{0}
};

#endif
