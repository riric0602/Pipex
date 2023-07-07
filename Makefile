# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 14:42:40 by rchbouki          #+#    #+#              #
#    Updated: 2023/06/27 20:34:08 by rchbouki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HEADER = -I ./includes
OBJS = ${SRCS:.c=.o}
SRCS =	pipex.c \
		ft_write.c \
		ft_printf.c \
		ft_substr.c \
		path_utils.c \
		pipex_utils.c \
		get_next_line.c \
		ft_printf_utils.c
NAME = pipex

GREEN = "\033[1;32m"
EOC = "\033[0;0m"

.c.o :
	@${CC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	@echo $(GREEN)"     Compiling Riri's Pipex..." $(EOC)
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all : ${NAME}

clean :
	@${RM} ${OBJS}

fclean : clean
	@${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re