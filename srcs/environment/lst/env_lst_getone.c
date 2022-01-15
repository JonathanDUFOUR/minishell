/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:03:08 by majacque          #+#    #+#             */
/*   Updated: 2022/01/15 08:24:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_env_lst.h"
#include "ft_string.h"

/*
	Return the value of the variable `name`,
	or NULL if a such variable is not set in the env list
*/
char	*env_lst_getone(t_env_lst const *const env, char const *name)
{
	t_env const	*curr = env->head;

	while (curr && ft_strcmp(name, curr->name))
		curr = curr->next;
	if (curr)
		return ((char *)curr->value);
	return (NULL);
}
