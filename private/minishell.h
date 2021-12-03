/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/03 19:29:37 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "t_token_lst.h"
# include "t_env_lst.h"

int	msh_pwd(t_token *args);
int	msh_env(t_token *args, t_env_lst *data); // TODO voir si on peut mettre __attribute__((nonnull)) que pour data

#endif
