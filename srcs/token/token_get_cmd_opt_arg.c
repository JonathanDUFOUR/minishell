/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_get_cmd_opt_arg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:45:39 by majacque          #+#    #+#             */
/*   Updated: 2021/12/18 19:12:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_string.h"
#include "ft_mem.h"

/* V1 */

static void	__get_size_and_len(t_token const *node, size_t *const size,
	size_t *const len)
{
	*size = 0;
	*len = 0;
	while (node && node->type != T_PIPE)
	{
		if (node->type == T_BUILTIN
			|| node->type == T_COMMAND
			|| node->type == T_OPTION
			|| node->type == T_ARGUMENT)
		{
			++*size;
			*len += ft_strlen(node->str);
		}
		node = node->next;
	}
}

static char	**__populate(char **output, t_token const *node)
{
	size_t	i;
	size_t	size;

	i = 0;
	while (node && node->type != T_PIPE)
	{
		if (node->type == T_BUILTIN
			|| node->type == T_COMMAND
			|| node->type == T_OPTION
			|| node->type == T_ARGUMENT)
		{
			size = ft_strlen(node->str) + 1;
			ft_memcpy(output[i], node->str, size);
			output[i + 1] = output[i] + size;
			++i;
		}
		node = node->next;
	}
	output[i] = NULL;
	return (output);
}

/*
	Allocate a new array of pointers
	and fill it with the strings contained in the given token node `command`
	and the next `n` token nodes
*/
char	**token_get_cmd_opt_arg(t_token const *const node)
{
	char	**output;
	size_t	size;
	size_t	len;

	__get_size_and_len(node, &size, &len);
	output = malloc((size + 1) * sizeof(char *) + (len + size) * sizeof(char));
	if (!output)
		return (NULL);
	output[0] = (char *)(output + size + 1);
	return (__populate(output, node));
}

/* V2 */
/*
static void	__get_size(t_token const *node, size_t *const size)
{
	*size = 0;
	while (node && node->type != T_PIPE)
	{
		if (node->type == T_BUILTIN
			|| node->type == T_COMMAND
			|| node->type == T_OPTION
			|| node->type == T_ARGUMENT)
			++*size;
		node = node->next;
	}
}

static char	**__populate(char **output, t_token const *node)
{
	size_t	i;

	i = 0;
	while (node && node->type != T_PIPE)
	{
		if (node->type == T_BUILTIN
			|| node->type == T_COMMAND
			|| node->type == T_OPTION
			|| node->type == T_ARGUMENT)
			output[i++] = node->str;
		node = node->next;
	}
	output[i] = NULL;
	return (output);
}

char	**token_get_cmd_opt_arg(t_token const *const node)
{
	char	**output;
	size_t	size;

	__get_size(node, &size);
	output = malloc((size + 1) * sizeof(char *));
	if (!output)
		return (NULL);
	return (__populate(output, node));
}
*/
