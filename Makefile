##
## Makefile for bomberman in /home/polydo_s/rendu/Bomberman
## 
## Made by Swann polydo_s
## Login   <polydo_s@epitech.net>
## 
## Started on  Tue Apr 28 16:18:00 2015 Swann polydo_s
## Last update Fri May 22 02:48:12 2015 clément jean
##

CXX		= g++
CXXFLAGS	= -W -Wall -Werror -Wextra -std=c++11 -g -g3 -ggdb
CXXFLAGS	+= -I./includes -I./lib/includes
LDFLAGS		= -Wl,--rpath=./lib/libs -lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -ldl
LDLIBS		= -L./lib/libs

NAME		= bomberman
RM		= rm -rf

BIN		= bin
SRC		= src

SRCS		= main.cpp			\
		  $(SRC)/MapGenerator.cpp	\
		  $(SRC)/AElement.cpp		\
		  $(SRC)/APlayer.cpp		\
		  $(SRC)/PhysicalPlayer.cpp	\
		  $(SRC)/Box.cpp		\
		  $(SRC)/Wall.cpp		\
		  $(SRC)/Bomberman.cpp		\
		  $(SRC)/Model.cpp		\
		  $(SRC)/AObject.cpp		\
		  $(SRC)/Cube.cpp		\
		  $(SRC)/Menu.cpp		\
		  $(SRC)/GenMap.cpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	mkdir -p $(BIN)
	$(CXX) $(OBJS) -o $(BIN)/$(NAME) $(LDLIBS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(BIN)

re: fclean all

.PHONY: all $(NAME) clean fclean re
