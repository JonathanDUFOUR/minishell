/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:24:40 by jodufour          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/01/20 14:42:23 by jodufour         ###   ########.fr       */
=======
/*   Updated: 2022/01/20 22:42:32 by jodufour         ###   ########.fr       */
>>>>>>> dev
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "ft_string.h"
#include "t_token_lst.h"

static int	__update(t_token_lst *const lst, t_token *const node,
	t_token *const next)
{
	next->next = node->next;
	next->prev = node;
	node->next = next;
	if (node == lst->tail)
		lst->tail = next;
	++lst->size;
	return (EXIT_SUCCESS);
}

static int	__split(t_token_lst *const lst, t_token *const node,
	t_sed *const sed, char const *ptr)
{
	t_token *const	next = token_new(NULL, node->type, (t_sed_lst){0});
	t_sed *const	cut = sed_new(NULL, UQUOTED);
	char const		*str0 = ft_strdup(ptr);
	char const		*str1 = ft_strndup(sed->str,
			ft_strchr(sed->str, ' ') - sed->str);

	if (!next || !cut || !str0 || !str1)
		return (ft_memdel((void *)&next), ft_memdel((void *)&cut),
			ft_memdel(&str0), ft_memdel(&str1), EXIT_FAILURE);
	free((void *)sed->str);
	cut->str = str0;
	cut->next = sed->next;
	sed->str = str1;
	sed->next = NULL;
	next->seds.head = cut;
	next->seds.tail = node->seds.tail;
	next->seds.size = sed_size(cut);
	node->seds.tail = sed;
	node->seds.size -= next->seds.size - 1;
	return (__update(lst, node, next));
}

static int	__evaluate(t_token_lst *const lst, t_token *const node,
	t_sed *const sed)
{
	char const	*tmp = sed->str;
	char const	*ptr;

	sed->str = ft_strtrim(sed->str, " ");
	ft_memdel(&tmp);
	if (!sed->str)
		return (EXIT_FAILURE);
	ptr = ft_strchr(sed->str, ' ');
	if (!ptr)
		return (EXIT_SUCCESS);
	while (*ptr == ' ')
		++ptr;
	return (__split(lst, node, sed, ptr));
}

static int	__browse(t_token_lst *const lst, t_token *const node)
{
	t_sed	*curr;

	curr = node->seds.head;
	while (curr)
	{
		if (curr->type == UQUOTED && __evaluate(lst, node, curr))
			return (EXIT_FAILURE);
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}

/*
	Split each token node in the given token `lst`
	that contains a sed that has both:
	- the UQUOTED type
	- a space in its `str` attribute
	into two token nodes
*/
int	token_lst_split(t_token_lst *const lst)
{
	t_token	*curr;

	curr = lst->head;
	while (curr)
	{
		if (__browse(lst, curr))
			return (EXIT_FAILURE);
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
