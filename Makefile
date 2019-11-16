# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 14:54:43 by ncolomer          #+#    #+#              #
#    Updated: 2019/11/16 18:00:56 by ncolomer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s
OBJS	=	$(SRCS:.s=.o)

NA		=	nasm
NA_FLAGS=	-f macho64
FLAGS 	=	-Wall -Werror -Wextra
NAME	=	libasm

%.o:			%.s
				$(NA) $(NA_FLAGS) $<

all:			$(NAME)

start:			re
				./$(NAME) < Makefile

$(NAME):		$(OBJS)
				gcc $(FLAGS) -o $(NAME) main.c $(OBJS)

clean:
				rm -rf $(OBJS)

fclean:			clean
				rm -rf $(NAME)

re:				fclean $(NAME)

.PHONY:			clean fclean re start