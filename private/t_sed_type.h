/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sed_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:48:11 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/10 17:34:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SED_TYPE_H
# define T_SED_TYPE_H

typedef enum e_sed_type	t_sed_type;

enum	e_sed_type
{
	UQUOTED,
	SQUOTED,
	DQUOTED
};

#endif
