/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:03:28 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 00:19:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PID_H
# define T_PID_H

# include <sys/types.h>

typedef struct s_pid	t_pid;

struct s_pid
{
	pid_t	id;
	t_pid	*next;
	t_pid	*prev;
};

int		pid_kill(t_pid const *const node, int const sig)
		__attribute__((nonnull));
int		pid_wait(t_pid const *const node)
		__attribute__((nonnull));

void	pid_delone(t_pid *node)
		__attribute__((nonnull));

t_pid	*pid_new(pid_t const id);

#endif
