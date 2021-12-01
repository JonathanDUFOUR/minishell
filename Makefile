# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 11:10:02 by jodufour          #+#    #+#              #
#    Updated: 2021/12/01 21:40:59 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC					=	clang -c -o
LINK				=	clang -o
MKDIR				=	mkdir -p
RM					=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME				=	minishell

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR				=	srcs/
OBJ_DIR				=	objs/
PRV_DIR				=	private/

FT_IO_DIR			=	libft_io/
FT_IO_INC_DIR		=	include/
FT_IO_INC_DIR		:=	${addprefix ${FT_IO_DIR}, ${FT_IO_INC_DIR}}

FT_MEM_DIR			=	libft_mem/
FT_MEM_INC_DIR		=	include/
FT_MEM_INC_DIR		:=	${addprefix ${FT_MEM_DIR}, ${FT_MEM_INC_DIR}}

FT_STRING_DIR		=	libft_string/
FT_STRING_INC_DIR	=	include/
FT_STRING_INC_DIR	:=	${addprefix ${FT_STRING_DIR}, ${FT_STRING_INC_DIR}}

#######################################
#              LIBRARIES              #
#######################################
FT_IO_A			=	libft_io.a
FT_IO_A			:=	${addprefix ${FT_IO_DIR}, ${FT_IO_A}}

FT_MEM_A		=	libft_mem.a
FT_MEM_A		:=	${addprefix ${FT_MEM_DIR}, ${FT_MEM_A}}

FT_STRING_A		=	libft_string.a
FT_STRING_A		:=	${addprefix ${FT_STRING_DIR}, ${FT_STRING_A}}

######################################
#            SOURCE FILES            #
######################################
SRC				=	\
					${addprefix builtins/,		\
						${addprefix cd/,		\
							core.c				\
						}						\
						${addprefix echo/,		\
							core.c				\
						}						\
						${addprefix env/,		\
							core.c				\
						}						\
						${addprefix exit/,		\
							core.c				\
						}						\
						${addprefix export/,	\
							core.c				\
						}						\
						${addprefix pwd/,		\
							core.c				\
						}						\
						${addprefix unset/,		\
							core.c				\
						}						\
					}							\
					${addprefix token/,			\
						token_lst_add_back.c	\
						token_lst_clear.c		\
						token_lst_delone.c		\
						token_lst_get.c			\
						token_lst_push_back.c	\
						token_new.c				\
					}							\
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
CFLAGS			=	-Wall -Wextra #-Werror
CFLAGS			+=	-MMD -MP
CFLAGS			+=	-I${PRV_DIR}
CFLAGS			+=	-I${FT_IO_INC_DIR}
CFLAGS			+=	-I${FT_MEM_INC_DIR}
CFLAGS			+=	-I${FT_STRING_INC_DIR}

LDFLAGS			=	-lreadline
LDFLAGS			+=	-L${FT_IO_DIR} -lft_io
LDFLAGS			+=	-L${FT_MEM_DIR} -lft_mem
LDFLAGS			+=	-L${FT_STRING_DIR} -lft_string

ifeq (${DEBUG}, 1)
	CFLAGS		+=	-g
endif

VG_OPT			=	--suppressions=ignoreliberror
VG_OPT			+=	--leak-check=full
VG_OPT			+=	--show-leak-kinds=all

#######################################
#                RULES                #
#######################################
${NAME}: ${OBJ} ${FT_IO_A} ${FT_MEM_A} ${FT_STRING_A}
	${LINK} $@ ${OBJ} ${LDFLAGS}

all: ${NAME}

-include ${DEP}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} $@ ${CFLAGS} $<

${FT_IO_A}:
	${MAKE} ${@F} -C ${@D}

${FT_MEM_A}:
	${MAKE} ${@F} -C ${@D}

${FT_STRING_A}:
	${MAKE} ${@F} -C ${@D}

clean:
	${RM} ${OBJ_DIR} ${NAME}

fclean:
	${RM} ${OBJ_DIR} ${NAME}
	${MAKE} $@ -C ${FT_IO_DIR}
	${MAKE} $@ -C ${FT_MEM_DIR}
	${MAKE} $@ -C ${FT_STRING_DIR}

re: clean all

fre: fclean all

-include /home/jodufour/Templates/mk_files/coffee.mk
-include /home/jodufour/Templates/mk_files/norm.mk

valgrind: ${NAME}
	$@ ${VG_OPT} ./$<

.PHONY: all clean fclean re fre valgrind
