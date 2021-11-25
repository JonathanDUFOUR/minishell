/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_limits.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:19:05 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 10:45:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIMITS_H
# define FT_LIMITS_H

# include <limits.h>

# define HHINT_MAX	CHAR_MAX
# define HHINT_MIN	CHAR_MIN

# define HHUINT_MAX	UCHAR_MAX
# define HHUINT_MIN	0

# define HINT_MAX	SHRT_MAX
# define HINT_MIN	SHRT_MIN

# define HUINT_MAX	USHRT_MAX
# define HUINT_MIN	0

# define LINT_MAX	LONG_MAX
# define LINT_MIN	LONG_MIN

# define LUINT_MAX	ULONG_MAX
# define LUINT_MIN	0

# define LLINT_MAX	LONG_MAX
# define LLINT_MIN	LONG_MIN

# define LLUINT_MAX	ULONG_MAX
# define LLUINT_MIN	0

#endif
