/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_builtin_name.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:10:32 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/14 03:12:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_BUILTIN_NAME_H
# define G_BUILTIN_NAME_H

# include <stddef.h>

static char const	*g_builtin_name[] = {
	"cd",
	"echo",
	"env",
	"exit",
	"export",
	"pwd",
	"unset",
	NULL
};

#endif
