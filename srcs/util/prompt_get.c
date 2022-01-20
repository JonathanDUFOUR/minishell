/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:39:49 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 18:06:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_string.h"
#include "ft_colors.h"
#include "minishell.h"
#include "t_env_lst.h"
#include "g_exit_status.h"

static char	*__get_pwd(t_env_lst *const env)
{
	char		*output;
	char const	*home = env_lst_getone(env, "HOME");
	char const	*pwd = env_lst_getone(env, "PWD");

	output = NULL;
	if (home && pwd)
	{
		if (strncmp(home, pwd, ft_strlen(home)))
			output = msh_str3join(" ", pwd, " ");
		else
			output = msh_str3join(" ~", pwd + ft_strlen(home), " ");
	}
	return (output);
}

static char	*__get_status(void)
{
	char	*output;
	char	*tmp;

	output = ft_utoa(g_exit_status);
	if (!output)
		return (NULL);
	tmp = output;
	output = msh_str3join("[", output, "]" "> ");
	ft_memdel(&tmp);
	return (output);
}

/*
	Allocate a new string and fill it with wanted prompt content
	Return the address of the created string
	Return NULL upon failure
*/
char	*prompt_get(t_env_lst *const env, char const *program)
{
	char const	*output = NULL;
	char const	*pwd = __get_pwd(env);
	char const	*status = __get_status();

	if (pwd && status)
		output = msh_str3join(program, pwd, status);
	ft_memdel(&pwd);
	ft_memdel(&status);
	return ((char *)output);
}
