/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:19:19 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 00:25:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TOKEN_TYPE_H
# define T_TOKEN_TYPE_H

typedef enum e_token_type	t_token_type;

/*
	Words:
	- File
	- Option
	- Command
	- Argument
	- Delimiter

	Operators:
	- Pipe
	- Redirect
*/
enum	e_token_type
{
	T_WORD,
	T_FILE,
	T_PIPE,
	T_INPUT,
	T_OPTION,
	T_BUILTIN,
	T_COMMAND,
	T_ARGUMENT,
	T_OPERATOR,
	T_DELIMITER,
	T_UNDEFINED,
	T_REDIRECTIN,
	T_REDIRECTOUT
};

#endif
