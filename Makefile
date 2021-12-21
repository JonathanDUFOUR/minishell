# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 11:10:02 by jodufour          #+#    #+#              #
#    Updated: 2021/12/21 02:07:17 by jodufour         ###   ########.fr        #
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

FT_STRING_DIR		=	libft_string/
FT_STRING_INC_DIR	=	include/
FT_STRING_INC_DIR	:=	${addprefix ${FT_STRING_DIR}, ${FT_STRING_INC_DIR}}

#######################################
#              LIBRARIES              #
#######################################
FT_IO_A			=	libft_io.a
FT_IO_A			:=	${addprefix ${FT_IO_DIR}, ${FT_IO_A}}

FT_STRING_A		=	libft_string.a
FT_STRING_A		:=	${addprefix ${FT_STRING_DIR}, ${FT_STRING_A}}

######################################
#            SOURCE FILES            #
######################################
SRC				=	\
					${addprefix builtins/,	\
						${addprefix cd/,	\
							cleanpath.c		\
							core.c			\
							getcdpath.c		\
							utils.c			\
						}					\
						${addprefix echo/,	\
							core.c			\
						}					\
						${addprefix env/,	\
							core.c			\
						}					\
						${addprefix exit/,	\
							core.c			\
						}					\
						${addprefix export/,\
							core.c			\
						}					\
						${addprefix pwd/,	\
							core.c			\
						}					\
						${addprefix unset/,	\
							core.c			\
						}					\
					}						\
					${addprefix environment/,				\
						env_addback.c						\
						env_clear.c							\
						env_delone.c						\
						env_new.c							\
						env_print.c							\
						env_to_envp.c						\
						get_env.c							\
						init_env.c							\
						put_env.c							\
						unset_env.c							\
					}										\
					${addprefix sed/,						\
						${addprefix lst/,					\
							sed_lst_add_back.c				\
							sed_lst_clear.c					\
							sed_lst_delone.c				\
							sed_lst_print.c					\
							sed_lst_push_back.c				\
						}									\
						sed_new.c							\
						sed_prev.c							\
						sed_print.c							\
						sed_size.c							\
					}										\
					${addprefix signal/,					\
						sigint.c							\
						sigquit.c							\
					}										\
					${addprefix token/,						\
						${addprefix lst/,					\
							token_lst_clear.c				\
							token_lst_delone.c				\
							token_lst_expand.c				\
							token_lst_get.c					\
							token_lst_here_doc.c			\
							token_lst_merge.c				\
							token_lst_print.c				\
							token_lst_push_back.c			\
							token_lst_remove_useless.c		\
							token_lst_sed.c					\
							token_lst_split.c				\
							token_lst_syntax_check.c		\
							token_lst_which_word.c			\
							token_lst_word_or_operator.c	\
						}									\
						count_args.c						\
						error_option.c						\
						token_clear.c						\
						token_delone.c						\
						token_expand.c						\
						token_get_cmd_opt_arg.c				\
						token_get.c							\
						token_here_doc.c					\
						token_merge.c						\
						token_new.c							\
						token_print.c						\
						token_sed.c							\
					}										\
					${addprefix util/,						\
						msh_readline.c						\
						msh_str3join.c						\
						namelen.c							\
					}										\
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
CFLAGS			+=	-I${FT_STRING_INC_DIR}

LDFLAGS			=	-lreadline
LDFLAGS			+=	-L${FT_IO_DIR} -lft_io
LDFLAGS			+=	-L${FT_STRING_DIR} -lft_string

ifeq (${DEBUG}, 1)
	CFLAGS		+=	-g
endif

#######################################
#                RULES                #
#######################################
${NAME}: ${OBJ} ${FT_IO_A} ${FT_STRING_A}
	${LINK} $@ ${OBJ} ${LDFLAGS}

all: ${NAME}

-include ${DEP}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} $@ ${CFLAGS} $<

${FT_IO_A}:
	${MAKE} ${@F} -C ${@D}

${FT_STRING_A}:
	${MAKE} ${@F} -C ${@D}

clean:
	${RM} ${OBJ_DIR} ${NAME} vgcore*

fclean:
	${RM} ${OBJ_DIR} ${NAME} vgcore*
	${MAKE} $@ -C ${FT_IO_DIR}
	${MAKE} $@ -C ${FT_STRING_DIR}

re: clean all

fre: fclean all

-include coffee.mk
-include norm.mk
-include valgrind.mk
-include update.mk

.PHONY: all clean fclean re fre
