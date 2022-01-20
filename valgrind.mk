# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    valgrind.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 15:19:04 by jodufour          #+#    #+#              #
#    Updated: 2022/01/20 19:14:03 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VG_OPT	=	--suppressions=ignoreliberror
VG_OPT	+=	--leak-check=full
VG_OPT	+=	--show-leak-kinds=all
VG_OPT	+=	--track-fds=yes
VG_OPT	+=	--trace-children=yes

valgrind:
	${MAKE} ${NAME} DEBUG=1
	$@ ${VG_OPT} ./${NAME}

.PHONY: valgrind
