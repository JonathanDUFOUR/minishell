/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_operators.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 02:35:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/03 19:09:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_OPERATORS_H
# define G_OPERATORS_H

# include <stddef.h>
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

static t_operator const		g_operators[] = {
{">", T_REDIRECT, T_FILE},
{"<", T_REDIRECT, T_FILE},
{">>", T_REDIRECT, T_FILE},
{"<<", T_REDIRECT, T_DELIMITER},
{"|", T_PIPE, T_COMMAND},
{0}
};

#endif
