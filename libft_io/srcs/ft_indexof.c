/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 06:22:26 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/17 19:12:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
	Return the index of the first character `c` found in the given string `str`
	Return -1 if `c` is not found
*/
ssize_t	ft_indexof(char const c, char const *str)
{
	ssize_t	i;

	i = 0;
	while (str[i] && c != str[i])
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}
