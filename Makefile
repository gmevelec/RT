# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenault <crenault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/13 14:58:48 by crenault          #+#    #+#              #
#    Updated: 2014/03/27 16:39:43 by gmevelec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT

HEAD = rt.h

SRC = antia_functions.c \
	  core_system.c \
	  color_functions.c \
	  color_functions_1.c \
	  color_functions_2.c \
	  errors.c \
	  init.c \
	  iref_functions.c \
	  key_functions.c \
	  matrix_functions.c \
	  mini_functions.c \
	  normal_functions.c \
	  objects_equations.c \
	  object_functions.c \
	  parser_functions.c \
	  parser_functions_1.c \
	  parser_functions_2.c \
	  parser_functions_3.c \
	  parser_functions_4.c \
	  parser_functions_5.c \
	  parser_functions_6.c \
	  parser_functions_7.c \
	  point_functions.c \
	  pixel_functions.c \
	  ray_functions.c \
	  rt.c \
	  soft_functions.c \
	  thread_functions.c \
	  vector_functions.c

OBJS = $(SRC:.c=.o)

LIB_FOLD = libft/

FLAGS = -Wall -Werror -Wextra -O3

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_FOLD)
	gcc $(FLAGS) -o $(NAME) $(OBJS) -L$(LIB_FOLD) -lft -L /usr/X11/lib \
	-lmlx -lXext -lX11

%.o: %.c $(HEAD)
	gcc $(FLAGS) -c $<

clean:
	rm -rf $(OBJS)
	make clean -C $(LIB_FOLD)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIB_FOLD)

re: fclean all

.PHONY: all clean fclean re
