/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env_lst.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:31:01 by majacque          #+#    #+#             */
/*   Updated: 2022/01/20 12:15:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ENV_LST_H
# define T_ENV_LST_H

# include <stddef.h>
# include "t_env.h"

typedef struct s_env_lst	t_env_lst;

struct	s_env_lst
{
	t_env	*head;
	t_env	*tail;
	size_t	size;
};

int		env_lst_init(t_env_lst *const lst, char const *const *envp)
		__attribute__((nonnull));
int		env_lst_putone(t_env_lst *const lst, char const *str)
		__attribute__((nonnull));

void	env_lst_clear(t_env_lst *const lst)
		__attribute__((nonnull));
void	env_lst_delone(t_env_lst *const lst, t_env *node)
		__attribute__((nonnull));
void	env_lst_print(t_env_lst *const lst)
		__attribute__((nonnull));
void	env_lst_push_back(t_env_lst *const lst, t_env *const node)
		__attribute__((nonnull));
void	env_lst_unset(t_env_lst *const lst, char const *name)
		__attribute__((nonnull));

char	*env_lst_getone(t_env_lst const *const lst, char const *name)
		__attribute__((nonnull));

char	**env_lst_to_envp(t_env_lst const *const lst)
		__attribute__((nonnull));

#endif
