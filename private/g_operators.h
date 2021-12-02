/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_operators.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 02:35:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/02 03:40:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_OPERATORS_H
# define G_OPERATORS_H

# include <stddef.h>

# ifndef OPERATOR_CHARS
#  define OPERATOR_CHARS	"<>|"
# endif

static char const	*g_operators[] = {
	">",
	"<",
	">>",
	"<<",
	"|",
	NULL
};

#endif
