/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:49:33 by majacque          #+#    #+#             */
/*   Updated: 2022/01/20 12:33:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"

/*
	Release all resources contained in the given env `lst`
	Update `lst` data accordingly
*/
void	env_lst_clear(t_env_lst *const lst)
{
	while (lst->head)
		env_lst_delone(lst, lst->head);
}
