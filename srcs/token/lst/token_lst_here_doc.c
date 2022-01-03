/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_here_doc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 01:00:13 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/02 21:10:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_token_lst.h"
#include "g_exit_status.h"

/*
	Proceed to each here-doc contained in the given token list
	Each T_DELIMITER token is changed to a T_INPUT token
	Each here-doc input is stored in the `str` atribute of the T_INPUT token
*/
int	token_lst_here_doc(t_token_lst *const tokens, t_env_lst *const env,
	char const *program)
{
	t_token	*curr;

	curr = tokens->head;
	while (curr)
	{
		if (curr->type == T_DELIMITER && token_here_doc(curr, env, program))
			return (g_exit_status = EXIT_FAILURE);
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
