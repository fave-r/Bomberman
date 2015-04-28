##
## Makefile for bomberman in /home/polydo_s/rendu/Bomberman
## 
## Made by Swann polydo_s
## Login   <polydo_s@epitech.net>
## 
## Started on  Tue Apr 28 16:18:00 2015 Swann polydo_s
## Last update Tue Apr 28 16:22:38 2015 Swann polydo_s
##

CC		= clang++
CPPFLAGS	+= -W -Wall -Werror -Wextra
CPPFLAGS	+= -I./includes

NAME		= bomberman
RM		= rm -rf

BIN		= bin
SRC		= src

SRCS		= main.cpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(BIN)/$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(BIN)/$(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
