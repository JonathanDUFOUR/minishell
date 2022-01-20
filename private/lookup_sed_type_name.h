/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_sed_type_name.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:04:27 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/10 17:41:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_SED_TYPE_NAME_H
# define LOOKUP_SED_TYPE_NAME_H

# include "t_sed_type.h"

typedef struct s_sed_type_name	t_sed_type_name;

struct s_sed_type_name
{
	t_sed_type const	type;
	char const			*name;
};

static t_sed_type_name const	g_sed_type_name[] = {
{UQUOTED, "UQUOTED"},
{SQUOTED, "SQUOTED"},
{DQUOTED, "DQUOTED"},
{0}
};

#endif
