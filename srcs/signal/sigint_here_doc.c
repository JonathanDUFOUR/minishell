/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:49:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/03 01:59:27 by jodufour         ###   ########.fr       */
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
	g_exit_status = 1 << 7;
	if (write(1, "\n", 1) == -1)
		perror(__func__);
	rl_replace_line("", 0);
	if (close(STDIN_FILENO) == -1)
		perror(__func__);
}

int	sigint_here_doc(void)
{
	if (signal(SIGINT, __handler) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
