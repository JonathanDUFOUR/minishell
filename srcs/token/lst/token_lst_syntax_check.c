/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_syntax_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:45:15 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 23:30:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"
#include "t_token_lst.h"
#include "g_exit_status.h"

static int	__error_msg(t_token const *const node, char const *program)
{
	g_exit_status = EXIT_FAILURE;
	ft_putstr_fd(program, STDERR_FILENO);
	if (node && node->type == T_FILE)
		ft_putstr_fd(": ambigous redirect\n", STDERR_FILENO);
	else
	{
		ft_putstr_fd(": syntax error near unexpected token `", STDERR_FILENO);
		if (node)
			ft_putstr_fd(node->str, STDERR_FILENO);
		else
			ft_putstr_fd("newline", STDERR_FILENO);
		ft_putstr_fd("'\n", STDERR_FILENO);
		g_exit_status = 2;
	}
	return (EXIT_FAILURE);
}

/*
	Check the good syntax of the given token `lst`
	Print an error message on the first syntax error encountered
*/
int	token_lst_syntax_check(t_token_lst *const lst, char const *program)
{
	t_token const	*curr = lst->head;

	while (curr)
	{
		if (curr == lst->head && curr->type == T_PIPE)
			return (__error_msg(curr, program));
		else if ((curr == lst->tail
				&& (curr->type == T_PIPE
					|| curr->type == T_REDIRECTIN
					|| curr->type == T_REDIRECTOUT))
			|| (curr->type == T_PIPE
				&& curr->next->type != T_BUILTIN
				&& curr->next->type != T_COMMAND
				&& curr->next->type != T_REDIRECTIN
				&& curr->next->type != T_REDIRECTOUT)
			|| (curr->type == T_REDIRECTIN
				&& curr->next->type != T_FILE
				&& curr->next->type != T_DELIMITER)
			|| (curr->type == T_REDIRECTOUT
				&& curr->next->type != T_FILE)
			|| (curr->type == T_FILE && curr->next->type == T_FILE))
			return (__error_msg(curr->next, program));
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
