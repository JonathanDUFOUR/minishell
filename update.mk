# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    update.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 15:21:39 by jodufour          #+#    #+#              #
#    Updated: 2021/12/20 20:55:02 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_IO_URL		=	git@gitlab.com:JonathanDUFOUR/libft_io.git
FT_STRING_URL	=	git@gitlab.com:JonathanDUFOUR/libft_string.git

update:
ifeq (${IO}, 1)
	${RM} ${FT_IO_DIR}
	git clone ${FT_IO_URL} ${FT_IO_DIR}
	${RM} ${FT_IO_DIR}.git*
endif
ifeq (${STRING}, 1)
	${RM} ${FT_STRING_DIR}
	git clone ${FT_STRING_URL} ${FT_STRING_DIR}
	${RM} ${FT_STRING_DIR}.git*
endif

.PHONY: update
