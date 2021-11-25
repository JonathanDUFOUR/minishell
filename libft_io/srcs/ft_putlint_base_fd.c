/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlint_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:03:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 02:34:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"

int	ft_putlint_base_fd(t_lint const nb, char const *base, int const fd)
{
	int		ret;
	char	*buff;
	t_uint	base_len;

	if (write(fd, "", 0) == -1 || !ft_isvalid(base))
		return (-1);
	buff = ft_litoa_base(nb, base);
	if (!buff)
		return (-1);
	base_len = (t_uint)ft_indexof(0, base);
	ret = (int)write(1, buff, ft_lintlen_base(nb, base_len));
	free(buff);
	return (ret);
}
