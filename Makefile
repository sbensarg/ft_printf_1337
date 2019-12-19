# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 19:05:06 by aamzil            #+#    #+#              #
#    Updated: 2019/12/18 18:17:28 by sbensarg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_printf.a
SRCS= *.c
FLAGS= -Wall -Wextra -Werror
CC=gcc
all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $(SRCS)
	ar -rc $(NAME) *.o
	ranlib $(NAME)

bonus:
	@$(CC) $(FLAGS) -c $(BSRCS)
	@ar -rc $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
re: fclean all
