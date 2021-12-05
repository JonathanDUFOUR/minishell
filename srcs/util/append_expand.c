/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 01:41:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/05 03:39:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "ft_mem.h"
#include "ft_string.h"
#include "minishell.h"

static char	*__get_expand(char const *str)
{
	(void)str;
	return (ft_strdup("[expand]"));
}

/*
	get the expanded value of the variable ptr is on
	and append it to str
	move ptr to the end of the variable name
*/
int	append_expand(char **const str, char const **const ptr)
{
	char	*tmp;
	char	*append;
	size_t	len;

	if (**ptr != '$')
		return (EXIT_SUCCESS);
	append = __get_expand(*ptr);
	if (!append)
		return (EXIT_FAILURE);
	len = varlen(*ptr);
	tmp = *str;
	*str = ft_strjoin(*str, append);
	ft_memdel(&tmp);
	ft_memdel(&append);
	if (!*str)
		return (EXIT_FAILURE);
	*ptr += len;
	return (EXIT_SUCCESS);
}
