/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/05 01:45:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stddef.h>

# ifndef PROMPT
#  define PROMPT	"$> "
# endif

int		append_expand(char **const str, char const **const ptr)
		__attribute__((nonnull));
int		append_literal(char **const str, char const **const ptr)
		__attribute__((nonnull));

size_t	varlen(char const *str)
		__attribute__((nonnull));

#endif
