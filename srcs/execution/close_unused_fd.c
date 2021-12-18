/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_unused_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:08:37 by majacque          #+#    #+#             */
/*   Updated: 2021/12/18 17:22:36 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdbool.h>

int	close_unused_fd(t_token *token, t_tube tube_in, t_tube tube_out, int fd_in, int fd_out) // t_pipeline data
{
	int	ret_close;

	ret_close = close(tube_in[1]);
	ret_close += close(tube_out[0]);
	if (fd_in > -1 || __is_pipe_before(token))
		ret_close += close(tube_in[0]);
	if (fd_out > -1 || __is_pipe_after(token))
		ret_close += close(tube_out[1]);
	if (ret_close > 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
