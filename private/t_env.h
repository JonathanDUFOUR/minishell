/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:25:37 by majacque          #+#    #+#             */
/*   Updated: 2022/01/15 08:06:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ENV_H
# define T_ENV_H

typedef struct s_env	t_env;

struct s_env
{
	char const	*name;
	char const	*value;
	t_env		*next;
	t_env		*prev;
};

t_env	*env_new(const char *str)
		__attribute__((nonnull));

#endif
