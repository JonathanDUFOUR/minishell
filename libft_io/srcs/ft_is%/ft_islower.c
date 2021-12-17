/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 02:03:18 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/17 19:59:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/*
	Return true if the given character `c` is a lowercase
	Return false else
*/
bool	ft_islower(int const c)
{
	return (c >= 'a' && c <= 'z');
}
