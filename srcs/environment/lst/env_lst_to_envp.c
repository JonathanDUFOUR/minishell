/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_to_envp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:08:16 by majacque          #+#    #+#             */
/*   Updated: 2022/01/15 08:15:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_string.h"

static void	__get_size_and_len(size_t *const size, size_t *const len,
	t_env_lst const *const env)
{
	t_env const	*curr = env->head;

	*size = env->size;
	*len = 0;
	while (curr)
	{
		*len += ft_strlen(curr->name) + ft_strlen(curr->value) + 1;
		curr = curr->next;
	}
}

static char	**__populate(char **output, t_env_lst const *const env)
{
	size_t		i;
	size_t		size;
	size_t		len0;
	size_t		len1;
	t_env const	*curr = env->head;

	i = 0;
	while (curr)
	{
		len0 = ft_strlen(curr->name);
		len1 = ft_strlen(curr->value);
		size = len0 + len1 + 2;
		ft_memcpy(output[i], curr->name, len0);
		ft_memcpy(output[i] + len0, "=", 1);
		ft_memcpy(output[i] + len0 + 1, curr->value, len1);
		output[i][size - 1] = 0;
		output[i + 1] = output[i] + size;
		++i;
		curr = curr->next;
	}
	output[i] = NULL;
	return (output);
}

/*
	Allocate a new array of pointers
	and fill it with strings according to the content of the given list `env`
	formated as followed:
		"name=value"
	Return the address of the new array of pointers
	Return NULL upon failure
*/
char	**env_lst_to_envp(t_env_lst const *const env)
{
	char	**output;
	size_t	size;
	size_t	len;

	__get_size_and_len(&size, &len, env);
	output = malloc((size + 1) * sizeof(char *)
			+ (len + size * 2) * sizeof(char));
	if (!output)
		return (NULL);
	output[0] = (char *)(output + size + 1);
	return (__populate(output, env));
}
