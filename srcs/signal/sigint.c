/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:40:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/20 21:09:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <limits.h>
#include <readline/readline.h>

static void	__sigemptyset(sigset_t *const mask)
{
	mask->__val[0] = 0;
	mask->__val[3] = UINT_MAX;
	mask->__val[5] = 0;
	mask->__val[6] = 64;
	mask->__val[7] = 8388608;
	mask->__val[8] = -1;
	mask->__val[10] = 6442450944;
	mask->__val[11] = 1;
	mask->__val[13] = 0;
	mask->__val[15] = 0;
}

static void	__sigint_handler(int sig, siginfo_t *si, void *uctx)
{
	(void)sig;
	(void)si;
	(void)uctx;
	if (write(1, "\n", 1) == -1)
		perror(__func__);
	rl_replace_line("", 0);
	if (rl_on_new_line())
		perror(__func__);
	rl_redisplay();
}

/*
	Setup the behavior to have when receiving a SIGINT
*/
int	setup_sigint_handle(void)
{
	struct sigaction	sigint;

	__sigemptyset(&sigint.sa_mask);
	sigint.sa_flags = SA_SIGINFO;
	sigint.sa_sigaction = __sigint_handler;
	if (sigaction(SIGINT, &sigint, NULL) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
