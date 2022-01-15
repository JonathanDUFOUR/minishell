/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_exedata.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:21:07 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 09:04:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_EXEDATA_H
# define T_EXEDATA_H

# include "t_fds.h"
# include "t_env_lst.h"
# include "t_pid_lst.h"

typedef struct s_exedata	t_exedata;

struct s_exedata
{
	t_fds		fds;
	char		**envp;
	char		**path;
	t_pid_lst	pids;
};

int	exedata_clear(t_exedata *const data)
	__attribute__((nonnull));
int	exedata_init(t_exedata *const data, t_env_lst *const env)
	__attribute__((nonnull));

#endif
