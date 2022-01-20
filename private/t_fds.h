/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fds.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:47:28 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 00:19:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FDS_H
# define T_FDS_H

typedef struct s_fds	t_fds;

struct s_fds
{
	int	in;
	int	out;
	int	save;
	int	tube[2];
};

int	fds_clear(t_fds *const fds)
	__attribute__((nonnull));
int	fds_init(t_fds *const fds)
	__attribute__((nonnull));

#endif
