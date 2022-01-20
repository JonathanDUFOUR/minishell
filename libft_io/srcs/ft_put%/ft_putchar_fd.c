/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:43:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 20:08:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
	Print the given cahracter `c` on the given file desciptor `fd`
	Return the number of printed bytes
	Return -1 upon failure
*/
int	ft_putchar_fd(char const c, int const fd)
{
	return ((int)write(fd, &c, 1));
}
