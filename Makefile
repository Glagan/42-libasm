# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 14:54:43 by ncolomer          #+#    #+#              #
#    Updated: 2019/11/16 15:40:14 by ncolomer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_strlen.asm
OBJS	=	$(SRCS:.asm=.o)

NA		=	nasm
NA_FLAGS=	-f macho64
FLAGS 	=	-Wall -Werror -Wextra
NAME	=	libasm

%.o:			%.asm
				$(NA) $(NA_FLAGS) $<

all:			$(NAME)

start:			$(NAME)
				./$(NAME)

$(NAME):		$(OBJS)
				gcc $(FLAGS) -o $(NAME) main.c $(OBJS)

clean:
				rm -rf $(OBJS)

fclean:			clean
				rm -rf $(NAME)

re:				fclean $(NAME)

.PHONY:			clean fclean re