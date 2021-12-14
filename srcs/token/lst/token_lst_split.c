/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:24:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/14 03:48:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "ft_mem.h"
#include "ft_string.h"
#include "t_token_lst.h"

static void	__update(t_token_lst *const tokens, t_token *const node,
	t_token *const next)
{
	next->next = node->next;
	next->prev = node;
	node->next = next;
	if (node == tokens->tail)
		tokens->tail = next;
	++tokens->size;
}

static int	__split(t_token_lst *const tokens, t_token *const node,
	t_sed *const sed, char const *ptr)
{
	t_token *const	next = token_new(NULL, T_WORD, (t_sed_lst){0});
	t_sed *const	cut = sed_new(NULL, UQUOTED);
	char const		*str0 = ft_strdup(ptr);
	char const		*str1 = ft_strndup(sed->str, ptr - sed->str);

	if (!next || !cut || !str0 || !str1)
	{
		ft_memdel((void *)&next);
		ft_memdel((void *)&cut);
		ft_memdel(&str0);
		ft_memdel(&str1);
		return (EXIT_FAILURE);
	}
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
	__update(tokens, node, next);
	return (EXIT_SUCCESS);
}

static int	__evaluate(t_token_lst *const tokens, t_token *const node,
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
	return (__split(tokens, node, sed, ptr));
}

static int	__browse(t_token_lst *const tokens, t_token *const node)
{
	t_sed	*curr;

	curr = node->seds.head;
	while (curr)
	{
		if (curr->type == UQUOTED && __evaluate(tokens, node, curr))
			return (EXIT_FAILURE);
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}

/*
	Split each token that contains a sed that has both:
	- the UQUOTED type
	- a space in its `str` attribute
	into two tokens
*/
int	token_lst_split(t_token_lst *const tokens)
{
	t_token	*curr;

	curr = tokens->head;
	while (curr)
	{
		if (__browse(tokens, curr))
			return (EXIT_FAILURE);
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
