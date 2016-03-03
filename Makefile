##
## Makefile for  in /home/maison_f/rendu/PSU_2015_my_ls
##
## Made by Maisonnave Florian
## Login   <maison_f@epitech.net>
##
## Started on  Sat Nov 28 16:58:07 2015 Maisonnave Florian
## Last update Thu Mar  3 15:41:56 2016 Maisonnave Florian
##

HEAD	= -Iinclude

CC	= gcc $(HEAD)

RM	= rm -f

CFLAGS	+= -Wextra -Wall

LDFLAGS	=

NAME	= my_ls

SRCS	= src/main.c \
	  src/fonctions.c \
	  src/fonctions2.c \
	  src/ls.c \
	  src/flags.c \
	  src/get_name.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
