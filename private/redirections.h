/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:11:26 by majacque          #+#    #+#             */
/*   Updated: 2021/12/18 16:44:56 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

# include "minishell.h"

int	redirections(t_token *token, t_tube tube_in, t_tube tube_out);
int	__open_files(t_token *token, int *fd_in, int *fd_out);

#endif
