/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:19:15 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 17:18:58 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_string.h"
#include "minishell.h"

static bool	__is_valid(const char *str)
{
	char	*tmp;
	int		len;

	tmp = (char *)str;
	len = 0;
	while (tmp[len])
		len++;
	if (len == 0)
		return (false);
	while (*tmp)
	{
		if (ft_strchr(VAR_CHARS, *tmp) == NULL)
			return (false);
		tmp++;
	}
	return (true);
}

int	msh_unset(t_env_lst *const env, t_token *const token)
{
	t_token const	*args = token->next;
	int				ret_value;

	ret_value = EXIT_SUCCESS;
	if (args == NULL)
		return (EXIT_SUCCESS);
	if (args->type == T_OPTION)
		return (error_option("unset: ", args->str));
	while (args && args->type == T_ARGUMENT)
	{
		if (__is_valid(args->str) == false)
		{
			ft_putstr_fd("unset: '", STDERR_FILENO);
			ft_putstr_fd(args->str, STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			ret_value = EXIT_FAILURE;
		}
		else
			env_lst_unset(env, args->str);
		args = args->next;
	}
	return (ret_value);
}
