/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthhint_base_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:24:50 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 20:14:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"

/*
	Print the given t_hhint `nb` converted in the given base
	on the given file descriptor `fd`
	Return the number of printed bytes
	Return -1 upon failure
*/
int	ft_puthhint_base_fd(t_hhint const nb, char const *base, int const fd)
{
	int		ret;
	char	*buff;
	t_uint	base_len;

	if (write(fd, "", 0) == -1 || !ft_isvalid(base))
		return (-1);
	buff = ft_hhitoa_base(nb, base);
	if (!buff)
		return (-1);
	base_len = (t_uint)ft_indexof(0, base);
	ret = (int)write(fd, buff, ft_hhintlen_base(nb, base_len));
	free(buff);
	return (ret);
}
