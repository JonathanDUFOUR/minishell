/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_default.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:40:33 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/18 15:06:00 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include "g_exit_status.h"

static void	__handler(int const sig __attribute__((unused)))
{
	g_exit_status = (1 << 7) | SIGINT; // FIX 128 --> 125
	if (write(1, "\n", 1) == -1)
		perror(__func__);
	rl_replace_line("", 0);
	if (rl_on_new_line())
		perror(__func__);
	rl_redisplay();
}

/*
	Setup the default behavior to have when receiving a SIGINT
*/
int	sigint_default(void)
{
	if (signal(SIGINT, __handler) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
