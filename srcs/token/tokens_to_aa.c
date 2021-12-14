/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_aa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:45:39 by majacque          #+#    #+#             */
/*   Updated: 2021/12/14 10:59:04 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "ft_string.h"
#include "ft_mem.h"

char	**tokens_to_aa(t_token *command, size_t n)
{
	char	**tab;
	size_t	i;

	tab = ft_calloc(n + 1, sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		tab[i] = ft_strdup(command->str);
		if (tab[i] == NULL)
		{
			free_tab2d(tab);
			return (NULL);
		}
		command = command->next;
		i++;
	}
	return (tab);
}
