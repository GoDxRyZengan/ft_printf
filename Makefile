# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 23:46:32 by hucoulon          #+#    #+#              #
#    Updated: 2020/02/17 19:35:35 by hucoulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRC =	./srcs/fonction.c \
		./srcs/ft_printf.c \
		./srcs/fonction_2.c \
		./srcs/fonction_3.c \
		./srcs/fonction_4.c \
		./srcs/gestion/recup_spe.c \
		./srcs/gestion/recup_cara.c \
		./srcs/gestion/recup_adress.c \
		./srcs/gestion/recup_str.c \
		./srcs/gestion/recup_int.c \
		./srcs/gestion/affichage_spe.c \
		./srcs/gestion/affichage_diu.c \
		./srcs/gestion/affichage_hexa.c \
		./srcs/gestion/affichage_cara.c \
		./srcs/gestion/affichage_str.c \
		./srcs/gestion/affichage_adress.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $^

.o : .c
	@gcc $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
