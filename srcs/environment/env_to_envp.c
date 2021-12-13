/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:08:16 by majacque          #+#    #+#             */
/*   Updated: 2021/12/13 19:53:04 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_mem.h"

char	**env_to_envp(t_env_lst *env)
{
	char	**envp;
	t_env	*elem;
	int		i;

	envp = ft_calloc(env->size + 1, sizeof(char *));
	if (envp == NULL)
		return (NULL);
	i = 0;
	elem = env->head;
	while (elem)
	{
		envp[i] = msh_str3join(elem->name, "=", elem->value);
		if (envp[i] == NULL)
		{
			free_tab2d(envp);
			return (NULL);
		}
		elem = elem->next;
		i++;
	}
	return (envp);
}
