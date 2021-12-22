/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 05:51:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/22 06:47:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>

static void	__handler(int const sig __attribute__((unused)))
{
	if (write(1, "\n", 1) == -1)
		perror(__func__);
	rl_replace_line("", 0);
	if (rl_on_new_line())
		perror(__func__);
	rl_redisplay();
}

/*
	Setup the behavior to have when receiving a SIGINT inside a here-doc
*/
int	sigint_here_doc(void)
{
	if (signal(SIGINT, __handler) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
