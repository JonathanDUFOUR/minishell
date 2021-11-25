/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 06:22:26 by jdufour           #+#    #+#             */
/*   Updated: 2021/11/21 13:04:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t	ft_indexof(char const c, char const *str)
{
	ssize_t	i;

	i = 0;
	while (str[i] && c != str[i])
		i++;
	if (str[i] == c)
		return (i);
	else
		return (-1);
}
