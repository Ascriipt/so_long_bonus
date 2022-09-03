# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 16:43:51 by maparigi          #+#    #+#              #
#    Updated: 2022/09/03 15:04:49 by maparigi         ###   ########.fr        #
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

NAME = so_long

CC = gcc

INC =	./includes

LIBFT_PATH = ./libft/
GNL_PATH = ./gnl/
LIBFT = ${LIBFT_PATH}libft.a
GNL = ${GNL_PATH}gnl.a

SRCS =	main.c			\
		exit.c			\
		utils.c			\
		parse.c			\
		moves.c			\
		gen_map.c		\
		check_map.c		\
		mlx_utilities.c	\

OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

CFLAGS = -Wall -Wextra -Werror -MMD -MP

FLAGS_MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

.c.o:
	@${CC} ${CFLAGS} -I${INC} -Imlx_linux -c $< -o $@

all:	${LIBFT} ${GNL} ${NAME}

${NAME}: ${OBJS}
	@echo "${Red}Compiling${NC} : ${Purple}mlx${NC}"
	@make -C mlx_linux all
	@echo "${Purple}mlx${NC} : has been successfully compiled."
	@echo "${Red}Compiling${NC} : ${Purple}${NAME}${NC}"
	${CC} ${OBJS} ${CFLAGS} ${LIBFT} ${GNL} ${FLAGS_MLX} -o ${NAME}
	@echo "${Purple}${NAME}${NC} : has been successfully compiled."

${LIBFT}:
	@make -C libft

${GNL}:
	@make -C gnl

val:	${NAME}
	valgrind \
	--leak-check=full --tool=memcheck \
	--show-reachable=yes \
	--track-fds=yes \
	--errors-for-leak-kinds=all \
	--show-leak-kinds=all ./${NAME} fichier.txt

clean:
	@rm -f ${OBJS} ${DEPS}
	@make -C libft clean
	@make -C gnl clean

fclean: clean
	@rm -f ${NAME}
	@make -C mlx_linux clean
	@make -C libft fclean
	@make -C gnl fclean

aclean: all clean

re: fclean all

-include : $(DEPS)

.PHONY: all clean fclean re bonus aclean val
