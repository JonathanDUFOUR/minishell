/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 02:04:19 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/17 20:00:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/*
	Return true if the given character `c` is an uppercase
	Return false else
*/
bool	ft_isupper(int const c)
{
	return (c >= 'A' && c <= 'Z');
}
