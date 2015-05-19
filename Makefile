##
## Makefile for bomberman in /home/polydo_s/rendu/Bomberman
## 
## Made by Swann polydo_s
## Login   <polydo_s@epitech.net>
## 
## Started on  Tue Apr 28 16:18:00 2015 Swann polydo_s
## Last update Tue May 19 20:49:13 2015 clément jean
##

CC		= clang++
CPPFLAGS	+= -W -Wall -Werror -Wextra -std=c++11 -g
CPPFLAGS	+= -I./includes -I./lib/includes
LDFLAGS		+= -L./lib/libs -Wl,--rpath=./lib/libs -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread

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
		  $(SRC)/Wall.cpp		\
		  $(SRC)/Bomberman.cpp		\
		  $(SRC)/Model.cpp		\
		  $(SRC)/AObject.cpp		\
		  $(SRC)/Cube.cpp		\
		  $(SRC)/Menu.cpp

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
