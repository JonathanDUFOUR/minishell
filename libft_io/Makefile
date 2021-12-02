# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 23:33:41 by jodufour          #+#    #+#              #
#    Updated: 2021/12/02 00:11:01 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################
#               COMANDS               #
#######################################
CC			=	clang -c -o
LINK		=	ar rcs
MKDIR		=	mkdir -p
RM			=	rm -rf

#######################################
#               LIBRARY               #
#######################################
NAME		=	libft_io
NAME_A		=	${NAME}.a
NAME_SO		=	${NAME}.so

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR		=	srcs/
PTF_SRC_DIR	=	ft_printf/
OBJ_DIR		=	objs/
INC_DIR		=	include/
PRV_DIR		=	private/

######################################
#            SOURCE FILES            #
######################################
SRC			=	\
				${addprefix ft_%intlen/,		\
					ft_hhintlen.c				\
					ft_hhuintlen.c				\
					ft_hintlen.c				\
					ft_huintlen.c				\
					ft_intlen.c					\
					ft_lintlen.c				\
					ft_llintlen.c				\
					ft_lluintlen.c				\
					ft_luintlen.c				\
					ft_uintlen.c				\
				}								\
				${addprefix ft_%intlen_base/,	\
					ft_hhintlen_base.c			\
					ft_hhuintlen_base.c			\
					ft_hintlen_base.c			\
					ft_huintlen_base.c			\
					ft_intlen_base.c			\
					ft_lintlen_base.c			\
					ft_llintlen_base.c			\
					ft_lluintlen_base.c			\
					ft_luintlen_base.c			\
					ft_uintlen_base.c			\
				}								\
				${addprefix ft_%toa/,			\
					ft_ctoa.c					\
					ft_hhitoa.c					\
					ft_hhutoa.c					\
					ft_hitoa.c					\
					ft_hutoa.c					\
					ft_itoa.c					\
					ft_litoa.c					\
					ft_llitoa.c					\
					ft_llutoa.c					\
					ft_lutoa.c					\
					ft_utoa.c					\
				}								\
				${addprefix ft_%toa_base/,		\
					ft_hhitoa_base.c			\
					ft_hhutoa_base.c			\
					ft_hitoa_base.c				\
					ft_hutoa_base.c				\
					ft_itoa_base.c				\
					ft_litoa_base.c				\
					ft_llitoa_base.c			\
					ft_llutoa_base.c			\
					ft_lutoa_base.c				\
					ft_utoa_base.c				\
				}								\
				${addprefix ft_ato%/,			\
					ft_atohhi.c					\
					ft_atohhu.c					\
					ft_atohi.c					\
					ft_atohu.c					\
					ft_atoi.c					\
					ft_atoli.c					\
					ft_atolli.c					\
					ft_atollu.c					\
					ft_atolu.c					\
					ft_atou.c					\
				}								\
				${addprefix ft_ato%_base/,		\
					ft_atohhi_base.c			\
					ft_atohhu_base.c			\
					ft_atohi_base.c				\
					ft_atohu_base.c				\
					ft_atoi_base.c				\
					ft_atoli_base.c				\
					ft_atolli_base.c			\
					ft_atollu_base.c			\
					ft_atolu_base.c				\
					ft_atou_base.c				\
				}								\
				${addprefix ft_is%/,			\
					ft_isalnum.c				\
					ft_isalpha.c				\
					ft_isascii.c				\
					ft_isdigit.c				\
					ft_islower.c				\
					ft_isprint.c				\
					ft_isspace.c				\
					ft_isupper.c				\
					ft_isvalid.c				\
				}								\
				${addprefix ft_printf/,			\
					${addprefix cvrt/,			\
						cvrt_b.c				\
						cvrt_c.c				\
						cvrt_d.c				\
						cvrt_o.c				\
						cvrt_p.c				\
						cvrt_prct.c				\
						cvrt_s.c				\
						cvrt_u.c				\
						cvrt_x.c				\
						putnil.c				\
						putnull.c				\
					}							\
					${addprefix utils/,			\
						int_strchr.c			\
						int_strlen.c			\
						int_wclen.c				\
						int_wstrlen.c			\
						int_wstrsize.c			\
					}							\
					ft_printf.c					\
					manage_cvrt.c				\
					manage_text.c				\
					padding.c					\
					parse_flags.c				\
					parse_fwidth.c				\
					parse_lmod.c				\
					parse_prec.c				\
				}								\
				${addprefix ft_put%/,			\
					ft_putbyte_fd.c				\
					ft_putbytes_fd.c			\
					ft_putchar_fd.c				\
					ft_putendl_fd.c				\
					ft_putstr_fd.c				\
					ft_putwchar_fd.c			\
				}								\
				${addprefix ft_put%int/,		\
					ft_puthhint_fd.c			\
					ft_puthhuint_fd.c			\
					ft_puthint_fd.c				\
					ft_puthuint_fd.c			\
					ft_putint_fd.c				\
					ft_putlint_fd.c				\
					ft_putllint_fd.c			\
					ft_putlluint_fd.c			\
					ft_putluint_fd.c			\
					ft_putuint_fd.c				\
				}								\
				${addprefix ft_put%int_base/,	\
					ft_puthhint_base_fd.c		\
					ft_puthhuint_base_fd.c		\
					ft_puthint_base_fd.c		\
					ft_puthuint_base_fd.c		\
					ft_putint_base_fd.c			\
					ft_putlint_base_fd.c		\
					ft_putllint_base_fd.c		\
					ft_putlluint_base_fd.c		\
					ft_putluint_base_fd.c		\
					ft_putuint_base_fd.c		\
				}								\
				ft_cat.c						\
				ft_convert_base.c				\
				ft_fddel.c						\
				ft_indexof.c					\
				ft_tolower.c					\
				ft_toupper.c					\
				get_next_line_utils.c			\
				get_next_line.c

######################################
#            OBJECT FILES            #
######################################
OBJ			=	${SRC:.c=.o}
OBJ			:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP			=	${OBJS:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		+=	-MMD -MP
CFLAGS		+=	-I${INC_DIR} -I${PRV_DIR}

ifeq (${DEBUG}, 1)
	CFLAGS	+=	-g
endif

LDFLAGS		=	

#######################################
#                RULES                #
#######################################
${NAME_A}:	${OBJ}
	${LINK} $@ ${LDFLAGS} $^

${NAME_SO}:	CFLAGS	+= -fPIC
${NAME_SO}:	LDFLAGS += -shared
${NAME_SO}:	LINK = clang -o
${NAME_SO}:	${OBJ}
	${LINK} $@ ${LDFLAGS} $^

all:	${NAME_A} ${NAME_SO} ${TEST}

-include ${DEP}

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJ_DIR}

fclean:
	${RM} ${OBJ_DIR} ${NAME_A} ${NAME_SO}

re:	fclean all

-include /home/jodufour/Templates/mk_files/coffee.mk
-include /home/jodufour/Templates/mk_files/norm.mk

.PHONY:	all clean fclean re
