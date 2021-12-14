/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_str3join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:51:21 by majacque          #+#    #+#             */
/*   Updated: 2021/12/14 10:59:36 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*msh_str3join(char const *s1, char const *s2, char const *s3)
{
	size_t	len;
	char	*dest;
	char	*d;

	if (!s1 || !s2 || !s3)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	d = dest;
	while (*s1)
		*d++ = *s1++;
	while (*s2)
		*d++ = *s2++;
	while (*s3)
		*d++ = *s3++;
	*d = 0;
	return (dest);
}
