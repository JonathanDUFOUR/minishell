/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 02:11:02 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/17 19:58:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
	Return true if the given character `c` is an alphanumeric
	Return false else
*/
bool	ft_isalnum(int const c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
