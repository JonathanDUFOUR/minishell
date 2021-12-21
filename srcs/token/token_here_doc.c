/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 01:20:41 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/21 06:14:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include "ft_io.h"
#include "ft_string.h"
#include "minishell.h"
#include "t_token.h"

static int	__interrupt_end(char const *str, char const *program)
{
	ft_putchar_fd('\n', STDERR_FILENO);
	ft_putstr_fd(program, STDERR_FILENO);
	ft_putstr_fd(": warning: here-document delimited by end-of-file (wanted `",
		STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putendl_fd("')", STDERR_FILENO);
	return (EXIT_SUCCESS);
}

static int	__get_content(t_token *const node, char const *program)
{
	char const	*tmp;
	char		*line;

	line = readline(HERE_DOC_PROMPT);
	while (line)
	{
		if (!ft_strcmp(line, node->str))
		{
			ft_memdel(&line);
			return (EXIT_SUCCESS);
		}
		tmp = node->seds.head->str;
		node->seds.head->str = msh_str3join(node->seds.head->str, line, "\n");
		ft_memdel(&tmp);
		ft_memdel(&line);
		if (!node->seds.head->str)
			return (EXIT_FAILURE);
		line = readline(HERE_DOC_PROMPT);
	}
	ft_memdel(&line);
	return (__interrupt_end(node->str, program));
}

/*
	Proceed to the current here-doc, getting the content from stdin,
	and storing it into the `str` attribute of the given token `node`
*/
int	token_here_doc(t_token *const node, t_env_lst *const env,
	char const *program)
{
	char const	*str = ft_ctoa(0);

	if (!str)
		return (EXIT_FAILURE);
	if (sed_lst_add_back(&node->seds, str, DQUOTED))
	{
		ft_memdel(&str);
		return (EXIT_FAILURE);
	}
	if (__get_content(node, program))
		return (EXIT_FAILURE);
	ft_memdel(&node->str);
	node->type = T_INPUT;
	if (token_expand(node, env) || token_merge(node))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
