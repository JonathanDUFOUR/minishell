/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_token_type_name.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:17:52 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/14 03:23:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_TOKEN_TYPE_NAME_H
# define LOOKUP_TOKEN_TYPE_NAME_H

# include "t_token_type.h"

typedef struct s_token_type_name	t_token_type_name;

struct s_token_type_name
{
	t_token_type const	type;
	char const			*name;
};

static t_token_type_name const		g_token_type_name[] = {
{T_WORD, "WORD"},
{T_FILE, "FILE"},
{T_PIPE, "PIPE"},
{T_OPTION, "OPTION"},
{T_BUILTIN, "BUILTIN"},
{T_COMMAND, "COMMAND"},
{T_ARGUMENT, "ARGUMENT"},
{T_OPERATOR, "OPERATOR"},
{T_REDIRECT, "REDIRECT"},
{T_DELIMITER, "DELIMITER"},
{T_UNDEFINED, "UNDEFINED"},
{0}
};

#endif
