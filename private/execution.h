/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:11:26 by majacque          #+#    #+#             */
/*   Updated: 2022/01/17 14:24:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <unistd.h>
# include "minishell.h"
# include "t_exedata.h"

int		exec_cmd(t_token_lst *const tokens, t_token *const token,
			t_env_lst *const env, t_exedata *const data)
		__attribute__((nonnull));
int		open_files(t_token const *const token, int *const fd_in,
			int *const fd_out, char const *program)
		__attribute__((nonnull));
int		pipeline(t_token_lst *const tokens, t_env_lst *const env,
			t_exedata *const data)
		__attribute__((nonnull));
int		redirect(t_token_lst *const tokens, t_token *const token,
			t_exedata *const data)
		__attribute__((nonnull));
int		redirect_in(t_token *const token, t_fds *const fds)
		__attribute__((nonnull));
int		redirect_out(t_token *const token, t_fds *const fds)
		__attribute__((nonnull));
int		run_cmd(t_token *const token, t_env_lst *const env,
			t_exedata *const data)
		__attribute__((nonnull));
int		setup_fork(t_token_lst *const tokens, t_token *const token,
			t_env_lst *const env, t_exedata *const data)
		__attribute__((nonnull));

#endif
