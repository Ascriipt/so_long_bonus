# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 16:08:31 by maparigi          #+#    #+#              #
#    Updated: 2022/06/11 17:00:48 by maparigi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------colors-----------#
NC=\033[0m

Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m
#---------------------------#

NAME = gnl.a

CC = gcc

INC = ../includes

SRCS = get_next_line.c \
	   get_next_line_utils.c \

OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

CFLAGS = -Wall -Wextra -Werror -MMD -MP

.c.o:
	${CC} ${CFLAGS} -I${INC} -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
	@echo "${Red}Compiling${NC} : ${Purple}gnl${NC}"
	ar rcs ${NAME} ${OBJS}
	@echo "${Purple}gnl${NC} : has been successfully compiled."

clean:
	rm -f ${OBJS} $(DEPS)

fclean: clean
	rm -f ${NAME}

re: fclean all

-include : $(DEPS)

.PHONY: all clean fclean re bonus