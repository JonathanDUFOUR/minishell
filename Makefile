# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 11:10:02 by jodufour          #+#    #+#              #
#    Updated: 2021/11/30 11:36:10 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC				=	clang -c -o
LINK			=	clang -o
MKDIR			=	mkdir -p
RM				=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME			=	minishell

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR			=	srcs/
OBJ_DIR			=	objs/
INC_DIR			=	
PRV_DIR			=	private/

FT_IO_DIR		=	libft_io/
FT_IO_INC_DIR	=	include/
FT_IO_INC_DIR	:=	${addprefix ${FT_IO_DIR}, ${FT_IO_INC_DIR}}

#######################################
#              LIBRARIES              #
#######################################
FT_IO_A			=	libft_io.a
FT_IO_A			:=	${addprefix ${FT_IO_DIR}, ${FT_IO_A}}

######################################
#            SOURCE FILES            #
######################################
SRC				=	\
					main.c

######################################
#            OBJECT FILES            #
######################################
OBJ				=	${SRC:.c=.o}
OBJ				:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP				=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS			=	-Wall -Wextra -Werror
CFLAGS			+=	-MMD -MP
CFLAGS			+=	-I${PRV_DIR}
CFLAGS			+=	-I${FT_IO_INC_DIR}

LDFLAGS			=	-lreadline
LDFLAGS			+=	-L${FT_IO_DIR} -lft_io

ifeq (${DEBUG}, 1)
	CFLAGS		+=	-g
endif

VG_OPT			=	--suppressions=ignoreliberror
VG_OPT			+=	--leak-check=full
VG_OPT			+=	--show-leak-kinds=all

#######################################
#                RULES                #
#######################################
${NAME}:	${OBJ} ${FT_IO_A}
	${LINK} $@ ${OBJ} ${LDFLAGS}

all:	${NAME}

-include ${DEP}

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} $@ ${CFLAGS} $<

${FT_IO_A}:
	${MAKE} ${@F} -C ${@D}

clean:
	${RM} ${OBJ_DIR} ${NAME}

fclean:
	${RM} ${OBJ_DIR} ${NAME}
	${MAKE} $@ -C ${FT_IO_DIR}

re:	clean all

fre:	fclean all

-include /home/jodufour/Templates/mk_files/coffee.mk
-include /home/jodufour/Templates/mk_files/norm.mk

valgrind:
	valgrind ${VG_OPT} ./minishell

.PHONY:	all clean fclean re fre valgrind
