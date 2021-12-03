/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:49:33 by majacque          #+#    #+#             */
/*   Updated: 2021/12/03 15:20:03 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"
#include "ft_mem.h"

void	env_clear(t_env_lst *data)
{
	while (data->head)
		env_delone(data, data->head);
	data->tail = NULL;
}
