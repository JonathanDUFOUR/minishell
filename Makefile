# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 11:10:02 by jodufour          #+#    #+#              #
#    Updated: 2022/05/20 01:47:57 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC					=	clang
LINK				=	clang
MKDIR				=	mkdir -p
RM					=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME				=	minishell.out

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
FT_IO_A				=	libft_io.a
FT_IO_A				:=	${addprefix ${FT_IO_DIR}, ${FT_IO_A}}

FT_STRING_A			=	libft_string.a
FT_STRING_A			:=	${addprefix ${FT_STRING_DIR}, ${FT_STRING_A}}

######################################
#            SOURCE FILES            #
######################################
SRC					=	\
						${addprefix builtins/,					\
							${addprefix cd/,					\
								cleanpath.c						\
								core.c							\
								getcdpath.c						\
								utils.c							\
							}									\
							${addprefix echo/,					\
								core.c							\
							}									\
							${addprefix env/,					\
								core.c							\
							}									\
							${addprefix exit/,					\
								core.c							\
							}									\
							${addprefix export/,				\
								core.c							\
							}									\
							${addprefix pwd/,					\
								core.c							\
							}									\
							${addprefix unset/,					\
								core.c							\
							}									\
						}										\
						${addprefix environment/,				\
							${addprefix lst/,					\
								env_lst_clear.c					\
								env_lst_delone.c				\
								env_lst_getone.c				\
								env_lst_init.c					\
								env_lst_print.c					\
								env_lst_push_back.c				\
								env_lst_putone.c				\
								env_lst_to_envp.c				\
								env_lst_unset.c					\
							}									\
							env_new.c							\
							env_print.c							\
						}										\
						${addprefix execution/,					\
							${addprefix pid/,					\
								${addprefix lst/,				\
									pid_lst_add_back.c			\
									pid_lst_clear.c				\
									pid_lst_delone.c			\
									pid_lst_kill.c				\
									pid_lst_push_back.c			\
									pid_lst_wait.c				\
								}								\
								pid_delone.c					\
								pid_kill.c						\
								pid_new.c						\
								pid_wait.c						\
							}									\
							exec_cmd.c							\
							exedata_clear.c						\
							exedata_init.c						\
							fds_clear.c							\
							fds_init.c							\
							open_files.c						\
							pipeline.c							\
							redirect_in.c						\
							redirect_out.c						\
							redirect.c							\
							run_cmd_utils.c						\
							run_cmd.c							\
							setup_fork.c						\
						}										\
						${addprefix sed/,						\
							${addprefix lst/,					\
								sed_lst_add_back.c				\
								sed_lst_clear.c					\
								sed_lst_delone.c				\
								sed_lst_print.c					\
								sed_lst_push_back.c				\
								sed_lst_type_count.c			\
							}									\
							sed_new.c							\
							sed_prev.c							\
							sed_print.c							\
							sed_size.c							\
						}										\
						${addprefix signal/,					\
							sigall_default.c					\
							sigall_mute.c						\
							sigall_reset.c						\
							sigint_default.c					\
							sigint_here_doc.c					\
							sigint_mute.c						\
							sigint_reset.c						\
							sigpipe_default.c					\
							sigpipe_mute.c						\
							sigpipe_reset.c						\
							sigquit_default.c					\
							sigquit_mute.c						\
							sigquit_reset.c						\
							sigterm_default.c					\
							sigterm_mute.c						\
							sigterm_reset.c						\
						}										\
						${addprefix token/,						\
							${addprefix lst/,					\
								token_lst_clear.c				\
								token_lst_delone.c				\
								token_lst_exec.c				\
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
								token_lst_type_count.c			\
								token_lst_which_word.c			\
								token_lst_word_or_operator.c	\
							}									\
							token_args_count.c					\
							token_clear.c						\
							token_delone.c						\
							token_expand.c						\
							token_get_cmd_opt_arg.c				\
							token_get.c							\
							token_here_doc.c					\
							token_last_input_str.c				\
							token_merge.c						\
							token_new.c							\
							token_print.c						\
							token_sed.c							\
						}										\
						${addprefix util/,						\
							error_argument.c					\
							error_option.c						\
							msh_str3join.c						\
							namelen.c							\
							prompt_get.c						\
							usage_err.c							\
						}										\
						main.c

######################################
#            OBJECT FILES            #
######################################
OBJ					=	${SRC:.c=.o}
OBJ					:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP					=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS				=	-c
CFLAGS				+=	-Wall -Wextra -Werror
CFLAGS				+=	-MMD -MP
CFLAGS				+=	-I${PRV_DIR}
CFLAGS				+=	-I${FT_IO_INC_DIR}
CFLAGS				+=	-I${FT_STRING_INC_DIR}

LDFLAGS				=	-lreadline
LDFLAGS				+=	-L${FT_IO_DIR} -lft_io
LDFLAGS				+=	-L${FT_STRING_DIR} -lft_string

ifeq (${DEBUG}, 1)
	CFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################
.PHONY: all clean fclean re fre

${NAME}: ${OBJ} ${FT_IO_A} ${FT_STRING_A}
	${LINK} ${OBJ} ${LDFLAGS} ${OUTPUT_OPTION}

all: ${NAME}

-include ${DEP}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} $< ${CFLAGS} ${OUTPUT_OPTION}

${FT_IO_A} ${FT_STRING_A}:
	${MAKE} ${@F} -C ${@D}

clean:
	${RM} ${OBJ_DIR} ${NAME} vgcore*

fclean:
	${RM} ${OBJ_DIR} ${NAME} vgcore*
	${MAKE} $@ -C ${FT_IO_DIR}
	${MAKE} $@ -C ${FT_STRING_DIR}

re: clean all

fre: fclean all

-include valgrind.mk
-include update.mk
-include ${HOME}/Templates/mk_files/coffee.mk
-include ${HOME}/Templates/mk_files/norm.mk
