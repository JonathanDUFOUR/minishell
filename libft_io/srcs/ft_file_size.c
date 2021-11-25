/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 06:22:12 by jdufour           #+#    #+#             */
/*   Updated: 2021/11/15 23:52:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>

ssize_t	ft_file_size(char const *file)
{
	struct stat	st;

	if (!file)
		return (-1);
	if (!stat(file, &st))
		return (st.st_size);
	else
		return (-1);
}
