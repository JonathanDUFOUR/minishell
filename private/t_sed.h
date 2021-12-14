/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:37:28 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/13 23:51:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SED_H
# define T_SED_H

# include <stddef.h>
# include "t_sed_type.h"

typedef struct s_sed	t_sed;

struct s_sed
{
	char const	*str;
	t_sed_type	type;
	t_sed		*next;
};

void	sed_print(t_sed const *const node)
		__attribute__((nonnull));

size_t	sed_size(t_sed const *const node)
		__attribute__((nonnull));

t_sed	*sed_new(char const *str, t_sed_type const type);
t_sed	*sed_prev(t_sed const *start, t_sed const *const node)
		__attribute__((nonnull));

#endif
