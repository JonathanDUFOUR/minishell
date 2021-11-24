/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token_lst.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:26:41 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/24 16:28:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TOKEN_LST_H
# define T_TOKEN_LST_H

# include <stddef.h>
# include "t_token.h"

typedef struct s_token_lst	t_token_lst;

struct s_token_lst
{
	t_token	*head;
	t_token	*tail;
	size_t	size;
};

#endif
