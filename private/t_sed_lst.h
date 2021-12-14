/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sed_lst.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:36:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/10 18:21:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SED_LST_H
# define T_SED_LST_H

# include "t_sed.h"

typedef struct s_sed_lst	t_sed_lst;

struct s_sed_lst
{
	t_sed	*head;
	t_sed	*tail;
	size_t	size;
};

int		sed_lst_add_back(t_sed_lst *const seds, char const *str,
			t_sed_type const type)
		__attribute__((nonnull (1, 2)));

void	sed_lst_clear(t_sed_lst *const seds)
		__attribute__((nonnull));
void	sed_lst_delone(t_sed_lst *const seds, t_sed *node)
		__attribute__((nonnull));
void	sed_lst_print(t_sed_lst const *const seds)
		__attribute__((nonnull));
void	sed_lst_push_back(t_sed_lst *const seds, t_sed *const node)
		__attribute__((nonnull));

#endif
