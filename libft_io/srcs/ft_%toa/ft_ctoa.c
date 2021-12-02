/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:58:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/14 23:34:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_ctoa(char const c)
{
	char	*output;

	output = malloc(2 * sizeof(char));
	if (!output)
		return (NULL);
	*output = c;
	*(output + 1) = 0;
	return (output);
}
