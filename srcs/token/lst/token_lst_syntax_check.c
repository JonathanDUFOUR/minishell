/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_syntax_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:45:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/15 22:23:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"
#include "t_token_lst.h"

static int	__error_msg(t_token const *const node, char const *program)
{
	ft_putstr_fd(program, STDERR_FILENO);
	ft_putstr_fd(": syntax error near unexpected token `", STDERR_FILENO);
	ft_putstr_fd(node->str, STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

/*
	Check the good syntax of the given list `tokens`
	Print an error message on the first syntax error encountered
	Return EXIT_SUCCESS if no any error were found
	Return EXIT_FAILURE else
*/
int	token_lst_syntax_check(t_token_lst *const tokens, char const *program)
{
	t_token const	*curr = tokens->head;

	if (curr && curr->type == T_PIPE)
		return (__error_msg(curr, program));
	if (curr)
		curr = curr->next;
	while (curr)
	{
		if ((curr->prev->type == T_REDIRECT
				&& curr->type != T_FILE
				&& curr->type != T_DELIMITER)
			|| (curr->prev->type == T_PIPE
				&& curr->type != T_BUILTIN
				&& curr->type != T_COMMAND)
			|| (curr == tokens->tail
				&& (curr->type == T_PIPE || curr->type == T_REDIRECT)))
			return (__error_msg(curr, program));
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
