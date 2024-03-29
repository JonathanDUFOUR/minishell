/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:45:55 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/18 19:43:26 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "ft_string.h"
#include "ft_io.h"
#include "g_exit_status.h"

/*
	Apply the input and output redirections for the current command/builtin
	Once done, remove the redirections tokens from the given list `tokens`
*/
int	redirect(t_token_lst *const tokens, t_token *const token,
	t_exedata *const data)
{
	t_token	*curr;
	t_token	*next;

	if (open_files(token, &data->fds.in, &data->fds.out, data->program))
		return (EXIT_FAILURE);
	if (g_exit_status == 1 << 7 || g_exit_status == 127 || g_exit_status == 126)
		return (EXIT_SUCCESS);
	if (redirect_in(token, &data->fds))
		return (EXIT_FAILURE);
	if (redirect_out(token, &data->fds))
		return (EXIT_FAILURE);
	curr = token;
	while (curr && curr->type != T_PIPE)
	{
		if (curr->type == T_REDIRECTIN || curr->type == T_REDIRECTOUT)
		{
			next = curr->next->next;
			token_lst_delone(tokens, curr->next);
			token_lst_delone(tokens, curr);
			curr = next;
		}
		else
			curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
