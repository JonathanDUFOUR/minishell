/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_typename.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:17:52 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/03 20:20:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_TYPENAME_H
# define LOOKUP_TYPENAME_H

# include "t_type.h"

typedef struct s_typename	t_typename;

struct s_typename
{
	t_type const	type;
	char const		*name;
};

static t_typename const		g_typename[] = {
{T_WORD, "WORD"},
{T_FILE, "FILE"},
{T_PIPE, "PIPE"},
{T_COMMAND, "COMMAND"},
{T_ARGUMENT, "ARGUMENT"},
{T_OPERATOR, "OPERATOR"},
{T_REDIRECT, "REDIRECT"},
{T_DELIMITER, "DELIMITER"},
{T_UNDEFINED, "UNDEFINED"},
{0}
};

#endif
