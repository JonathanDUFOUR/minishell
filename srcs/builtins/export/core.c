/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:19:04 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/03 19:30:02 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "e_ret.h"
#include "t_env_lst.h"
#include "t_token_lst.h"

int	msh_export(t_token_lst *args, t_env_lst *data) // TODO export()
{
	return (SUCCESS);
}
/*
 * export :
 * si on fait comme bash --posix --> fait un env en ordre alphabetique sous ce format --> "export NAME="value""
 * si on suit le man --> undifined (donc une occasion de ne rien faire XD)
 *
 * export NAME --> ne fait rien
 * 
 * export NAME= :
 * si NAME n'existe pas --> cree NAME et set sa valeur a rien
 * si NAME existe --> set sa valeur a rien
 * 
 * export NAME=value :
 * si NAME n'existe pas --> cree NAME et set sa valeur a value
 * si NAME existe --> set sa valeur a value
 * 
 * Pas de maximum pour le nombre d'argument
 */