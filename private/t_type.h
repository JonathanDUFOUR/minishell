/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_type.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:19:19 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/02 03:42:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TYPE_H
# define T_TYPE_H

typedef enum e_type	t_type;

/*
	Words:
	- File
	- Option
	- Command
	- Argument

	Operators:
	- Pipe
	- Redirection
*/
enum	e_type
{
	T_WORD,
	T_FILE,
	T_PIPE,
	T_OPTION,
	T_COMMAND,
	T_ARGUMENT,
	T_OPERATOR,
	T_UNDEFINED,
	T_REDIRECTION
};

#endif
