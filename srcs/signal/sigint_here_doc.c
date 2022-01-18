/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:49:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/18 15:06:13 by majacque         ###   ########.fr       */
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
	g_exit_status = 1 << 7; // FIX 128 --> 125
	if (write(1, "\n", 1) == -1)
		perror(__func__);
	rl_replace_line("", 0);
	if (close(STDIN_FILENO) == -1)
		perror(__func__);
}

/*
	Setup the default behavior to have when receiving a SIGINT inside a here-doc
*/
int	sigint_here_doc(void)
{
	if (signal(SIGINT, __handler) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
