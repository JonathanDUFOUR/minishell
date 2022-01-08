/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:23:45 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 03:10:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"

/*
	Release the resources of the given struct `data`
*/
void	data_clear(t_exec_data *data)
{
	if (data->fd_in > 2)
		close(data->fd_in);
	if (data->fd_out > 2)
		close(data->fd_out);
	close(data->tubes[0][0]);
	close(data->tubes[0][1]);
	close(data->tubes[1][0]);
	close(data->tubes[1][1]);
	free(data->envp);
	free(data->path);
}
