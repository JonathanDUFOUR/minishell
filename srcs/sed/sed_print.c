/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:18:56 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 12:18:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "t_sed.h"
#include "lookup_sed_type_name.h"

/*
	Print the given sed `node` data
*/
void	sed_print(t_sed const *const node)
{
	int	i;

	if (0)
		printf("%15s: %p\n", "node", node);
	if (1)
		printf("%15s: %s\n", "node->str", node->str);
	i = 0;
	while (g_sed_type_name[i].name && node->type != g_sed_type_name[i].type)
		++i;
	if (1)
		printf("%15s: %s\n", "node->type", g_sed_type_name[i].name);
	if (0)
		printf("%15s: %p\n", "node->next", node->next);
}
