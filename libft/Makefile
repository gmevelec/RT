# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenault <crenault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 20:54:30 by ygudusze          #+#    #+#              #
#    Updated: 2014/03/22 12:42:41 by crenault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR = ./
INCDIR = ./
OBJDIR = ./

NAME = libft.a

EXEC = memset.c bzero.c memcpy.c memccpy.c memmove.c \
		memchr.c memcmp.c \
		strdup.c strcpy.c strncpy.c \
		strcat.c strncat.c strlcat.c \
		strchr.c strrchr.c strstr.c strnstr.c \
		isalpha.c isdigit.c isalnum.c isascii.c isprint.c isspace.c \
		atod.c atoi.c atoi_long.c strlen.c \
		strcmp.c strncmp.c \
		putchar.c putstr.c putnbr.c putendl.c \
		putchar_fd.c putstr_fd.c putnbr_fd.c putendl_fd.c \
		memalloc.c memdel.c strnew.c strdel.c strclr.c \
		striter.c striteri.c \
		strmap.c strmapi.c \
		strequ.c strnequ.c \
		strsub.c strjoin.c strtrim.c strsplit.c \
		itoa.c \
		tolower.c toupper.c \
		lstnew.c lstdelone.c lstdel.c lstadd.c lstpush.c \
		lstiter.c lstmap.c get_next_line.c math.c math2.c

SRC = $(addprefix $(OBJDIR),$(EXEC))
OBJ = $(patsubst %.c,$(OBJDIR)%.o,$(EXEC))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

all: $(NAME)
	ranlib $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
