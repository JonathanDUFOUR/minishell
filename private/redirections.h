/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:11:26 by majacque          #+#    #+#             */
/*   Updated: 2022/01/07 23:59:43 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

# include <unistd.h>
# include "minishell.h"

typedef int					t_tube[2];

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

int		close_unused_fd(t_token *token, t_exec_data *data)
		__attribute__((nonnull));
int		exec_cmd(t_token_lst *const tokens, t_token *token, t_env_lst *env,
			t_exec_data *data)
		__attribute__((nonnull));
int		open_files(t_token *token, int *fd_in, int *fd_out)
		__attribute__((nonnull));
int		redirections(t_token_lst *const tokens, t_token *token,
			t_exec_data *data)
		__attribute__((nonnull));
int		run_cmd(t_token *token, t_env_lst *env, t_exec_data *data)
		__attribute__((nonnull));
int		setup_fork(t_token_lst *const tokens, t_token *token, t_env_lst *env,
			t_exec_data *data)
		__attribute__((nonnull));

int		data_init(t_exec_data *data, t_env_lst *env)
		__attribute__((nonnull));
int		close_tubes(t_exec_data *data)
		__attribute__((nonnull));
void	data_clear(t_exec_data *data)
		__attribute__((nonnull));

#endif
