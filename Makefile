# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 14:54:43 by ncolomer          #+#    #+#              #
#    Updated: 2019/11/17 20:47:12 by ncolomer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s
OBJS		=	$(SRCS:.s=.o)
BONUS_SRCS	=	ft_atoi_base_bonus.s ft_list_size_bonus.s ft_list_push_front_bonus.s \
				ft_list_remove_if_bonus.s ft_list_sort_bonus.s
BONUS_OBJS	=	$(BONUS_SRCS:.s=.o)

NA			=	nasm
NA_FLAGS	=	-f macho64
FLAGS 		=	-Wall -Werror -Wextra
NAME		=	libasm
BONUS		=	libasm_bonus

%.o:			%.s
				$(NA) $(NA_FLAGS) $<

all:			$(NAME)

test:			re
				./$(NAME) < Makefile

$(NAME):		$(OBJS)
				gcc $(FLAGS) -o $(NAME) main.c $(OBJS)

clean:
				rm -rf $(OBJS) $(BONUS_OBJS)

fclean:			clean
				rm -rf $(NAME) $(BONUS)

re:				fclean $(NAME)

bonus:			$(BONUS_OBJS)
				gcc $(FLAGS) -o $(BONUS) main_bonus.c $(BONUS_OBJS)

test_bonus:		fclean bonus
				./$(BONUS) < Makefile

.PHONY:			clean fclean re start