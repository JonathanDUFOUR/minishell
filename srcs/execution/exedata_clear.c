/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exedata_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:23:45 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 09:22:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"
#include "ft_string.h"
#include "t_exedata.h"

/*
	Release the resources of the given `data`
*/
int	exedata_clear(t_exedata *const data)
{
	ft_memdel(&data->envp);
	ft_memdel(&data->path);
	pid_lst_clear(&data->pids);
	if (fds_clear(&data->fds))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
