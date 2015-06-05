##
## Makefile for bomberman in /home/polydo_s/rendu/Bomberman
##
## Made by Swann polydo_s
## Login   <polydo_s@epitech.net>
#1;2802;0c#
## Started on  Tue Apr 28 16:18:00 2015 Swann polydo_s
## Last update Fri Jun  5 20:08:56 2015 clément jean
##

CXX		= g++

CXXFLAGS	= -W -Wall -Werror -Wextra -std=c++11

CXXFLAGS	+= -I./includes -I./lib/includes

LDFLAGS		= -Wl,--rpath=./lib/libs -lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -ldl -lSDL2_image -lSDL2_ttf

FMOD		= ./lib/fmod/libfmod.so

LDLIBS		= -L./lib/libs -Wl,--rpath=./lib/fmod $(FMOD)

NAME		= bomberman
RM		= rm -rf

BIN		= bin
SRC		= src

SRCS		= main.cpp			\
		  $(SRC)/APlayer.cpp		\
		  $(SRC)/PhysicalPlayer.cpp	\
		  $(SRC)/Box.cpp		\
		  $(SRC)/Wall.cpp		\
		  $(SRC)/Bomberman.cpp		\
		  $(SRC)/Model.cpp		\
		  $(SRC)/AObject.cpp		\
		  $(SRC)/Cube.cpp		\
		  $(SRC)/Menu.cpp		\
		  $(SRC)/Map.cpp		\
		  $(SRC)/TexturePool.cpp	\
		  $(SRC)/ModelPool.cpp		\
		  $(SRC)/Parseur.cpp		\
		  $(SRC)/Bomb.cpp		\
		  $(SRC)/Fire.cpp		\
                  $(SRC)/Options.cpp            \
		  $(SRC)/Music.cpp		\

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
