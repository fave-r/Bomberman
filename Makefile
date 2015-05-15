##
## Makefile for bomberman in /home/polydo_s/rendu/Bomberman
## 
## Made by Swann polydo_s
## Login   <polydo_s@epitech.net>
## 
## Started on  Tue Apr 28 16:18:00 2015 Swann polydo_s
## Last update Sat May 16 00:10:08 2015 clément jean
##

CC		= clang++
CPPFLAGS	+= -W -Wall -Werror -Wextra -std=c++11
CPPFLAGS	+= -I./includes -I./lib/includes
LDFLAGS		= -L./lib/libs -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lSDL -lpthread

NAME		= bomberman
RM		= rm -rf

BIN		= bin
SRC		= src

SRCS		= main.cpp			\
		  $(SRC)/MapGenerator.cpp	\
		  $(SRC)/AElement.cpp		\
		  $(SRC)/ACharacter.cpp		\
		  $(SRC)/APlayer.cpp		\
		  $(SRC)/PhysicalPlayer.cpp	\
		  $(SRC)/Box.cpp		\
		  $(SRC)/Wall.cpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	mkdir -p $(BIN)
	$(CC) $(OBJS) -o $(BIN)/$(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(BIN)

re: fclean all

.PHONY: all $(NAME) clean fclean re
