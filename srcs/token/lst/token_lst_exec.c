/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:59:27 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 16:07:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_io.h"
#include "ft_string.h"
#include "minishell.h"
#include "execution.h"

static bool	__is_numeric(char const *str)
{
	while (ft_isspace(*str))
		++str;
	if (!*str)
		return (false);
	if ((*str == '+' || *str == '-') && ft_isdigit(*(str + 1)))
		++str;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		++str;
	}
	while (ft_isspace(*str))
		++str;
	if (*str)
		return (false);
	return (true);
}

static bool	__will_exit(t_token const *node)
{
	t_uint	arg_count;

	while (node)
	{
		if (node->type == T_BUILTIN && !ft_strcmp(node->str, "exit"))
			break ;
		node = node->next;
	}
	if (!node)
		return (false);
	arg_count = token_args_count(node);
	while (node && node->type != T_ARGUMENT)
		node = node->next;
	if (arg_count > 1 && __is_numeric(node->str))
		return (false);
	return (true);
}

int	token_lst_exec(t_token_lst *const tokens, t_env_lst *const env,
	char const *program)
{
	t_exedata	data;
	int			termin;
	int			termout;

	if (exedata_init(&data, env, program))
		return (EXIT_FAILURE);
	if (token_lst_type_count(tokens, T_PIPE)
		|| token_lst_type_count(tokens, T_COMMAND))
		return (pipeline(tokens, env, &data) | exedata_clear(&data));
	termin = dup(STDIN_FILENO);
	termout = dup(STDOUT_FILENO);
	if ((termin == -1 || termout == -1 || __will_exit(tokens->head))
		&& ft_fddel(&termin) | ft_fddel(&termout))
		return (exedata_clear(&data) | EXIT_FAILURE);
	if (exec_cmd(tokens, tokens->head, env, &data))
		return (exedata_clear(&data) | ft_fddel(&termin) | ft_fddel(&termout)
			| EXIT_FAILURE);
	if ((close(STDIN_FILENO) | close(STDOUT_FILENO)) == -1
		|| dup2(termin, STDIN_FILENO) == -1
		|| dup2(termout, STDOUT_FILENO) == -1
		|| (ft_fddel(&termin) | ft_fddel(&termout)))
		return (exedata_clear(&data) | ft_fddel(&termin) | ft_fddel(&termout)
			| EXIT_FAILURE);
	return (exedata_clear(&data) | sigall_default() | EXIT_SUCCESS);
}
