# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/08 14:20:14 by aderby            #+#    #+#              #
#    Updated: 2017/08/14 03:30:43 by aderby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

C_FIL = ft_freeprintf.c ft_pidstuff.c ft_printf.c libfuncs1.c libfuncs2.c \
		libfuncs3.c libfuncs4.c libfuncs5.c libfuncs6.c libfuncswchar.c \
		libfuncswchar2.c manageformat.c managepcent.c precentstuff.c \
		setstuff.c signedintstuff.c stringstuff.c unionstuff.c \
		unsignedintstuff.c widestuff.c widestuff2.c

O_FIL = *.o

GCC_FLAGS = gcc -Wall -Wextra -Werror -c

all: $(NAME)

$(O_FIL): $(C_FIL)
	$(GCC_FLAGS) $(C_FIL)

$(NAME): $(O_FIL)
	ar rcs $(NAME) $(O_FIL)

clean:
		rm -f $(O_FIL)

fclean: clean
		rm -f $(NAME)

re: fclean all
