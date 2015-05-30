##
## Makefile for bomberman in /home/polydo_s/rendu/Bomberman
##
## Made by Swann polydo_s
## Login   <polydo_s@epitech.net>
##
## Started on  Tue Apr 28 16:18:00 2015 Swann polydo_s
## Last update Sat May 30 17:23:47 2015 Leo Thevenet
##

CXX		= g++
CXXFLAGS	= -W -Wall -Werror -Wextra -std=c++11 -g
CXXFLAGS	+= -I./includes -I./lib/includes
LDFLAGS		= -Wl,--rpath=./lib/libs -lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -ldl
LDLIBS		= -L./lib/libs -lSDL_image -lSDL2_ttf

NAME		= bomberman
RM		= rm -rf

BIN		= bin
SRC		= src

SRCS		= main.cpp			\
		  $(SRC)/MapGenerator.cpp	\
		  $(SRC)/APlayer.cpp		\
		  $(SRC)/PhysicalPlayer.cpp	\
		  $(SRC)/Box.cpp		\
		  $(SRC)/Wall.cpp		\
		  $(SRC)/Bomberman.cpp		\
		  $(SRC)/Model.cpp		\
		  $(SRC)/AObject.cpp		\
		  $(SRC)/Cube.cpp		\
		  $(SRC)/Menu.cpp		\
		  $(SRC)/GenMap.cpp		\
		  $(SRC)/TexturePool.cpp	\
		  $(SRC)/ModelPool.cpp		\
		  $(SRC)/Parseur.cpp		\
		  $(SRC)/Bomb.cpp		\
		  $(SRC)/Fire.cpp		\
                  $(SRC)/Options.cpp            \

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
