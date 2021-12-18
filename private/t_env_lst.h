/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env_lst.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:31:01 by majacque          #+#    #+#             */
/*   Updated: 2021/12/18 20:21:36 by jodufour         ###   ########.fr       */
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

t_env	*env_new(const char *str)
		__attribute__((nonnull));

void	env_addback(t_env_lst *env, t_env *new_elem)
		__attribute__((nonnull));
void	env_delone(t_env_lst *const env, t_env *elem)
		__attribute__((nonnull));
void	env_clear(t_env_lst *const env)
		__attribute__((nonnull));
void	env_print(t_env_lst *const env)
		__attribute__((nonnull));

int		init_env(t_env_lst *const env, char const *const *envp)
		__attribute__((nonnull));
int		put_env(const char *str, t_env_lst *const env)
		__attribute__((nonnull));

void	unset_env(const char *str, t_env_lst *const env)
		__attribute__((nonnull));

char	*get_env(const char *name, t_env_lst *const env)
		__attribute__((nonnull));

char	**env_to_envp(t_env_lst const *const env)
		__attribute__((nonnull));

#endif
