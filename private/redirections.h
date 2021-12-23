/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:11:26 by majacque          #+#    #+#             */
/*   Updated: 2021/12/21 15:01:47 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

# include "minishell.h"
# include <unistd.h>

typedef int	t_tube[2];

typedef struct s_exec_data	t_exec_data;

struct s_exec_data
{
	t_tube	tubes[2];
	int		tube_in;
	int		tube_out;
	int		fd_in;
	int		fd_out;
	char	**envp;
	char	**path;
	
};

int		setup_fork(t_token *token, t_env_lst *env, t_exec_data *data)
		__attribute__((nonnull));
int		exec_cmd(t_token *token, t_env_lst *env, t_exec_data *data)
		__attribute__((nonnull));

int	redirections(t_token *token, t_exec_data *data);
int	__open_files(t_token *token, int *fd_in, int *fd_out);

#endif
