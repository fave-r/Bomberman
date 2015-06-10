##
## Makefile for bomberman in /home/polydo_s/rendu/Bomberman
##
## Made by Swann polydo_s
## Login   <polydo_s@epitech.net>
##
## Started on  Tue Apr 28 16:18:00 2015 Swann polydo_s
## Last update Tue Jun  9 16:29:01 2015 Leo Thevenet
##

CXX		= g++

CXXFLAGS	= -W -Wall -Werror -Wextra -std=c++11

CXXFLAGS	+= -I./includes -I./lib/includes

LDFLAGS		= -Wl,--rpath=./lib/libs -lgdl_gl -lGL -lpthread -lGLEW -lrt -lfbxsdk -lSDL2 -lSDL2_ttf
LDFLAGS		+= -lSDL2_image -ldl -L./lib/libvpx.a -lGLU -lvpx

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
		  $(SRC)/ABonus.cpp		\
		  $(SRC)/BonusSpeed.cpp		\
		  $(SRC)/BonusForce.cpp		\
		  $(SRC)/BonusBomb.cpp		\
		  $(SRC)/MapSaver.cpp		\
		  $(SRC)/playvpx.cpp		\
		  $(SRC)/HighScore.cpp		\
		  $(SRC)/Score.cpp		\

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
