//
// Menu.hh for Menu.hh in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 20:36:11 2015 clément jean
// Last update Mon Jun  8 20:44:30 2015 clément jean
//

#ifndef __MENU_HH__
# define __MENU_HH__

#include <Game.hh>
#include <SdlContext.hh>
#include <AShader.hh>
#include <BasicShader.hh>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cstdlib>
#include <SDL2/SDL_ttf.h>

#include "Bomberman.hh"
#include "Music.hh"

class Menu
{
public:
  Menu();
  ~Menu();
  void		initialize();
  bool		update();
  bool		Check_Path();
  void		draw();
  void		SetScreen();
  void		PutStringOnScreen(SDL_Color, SDL_Rect, std::string);
  void		MoveCursor(int);
  void		launchBomberman(Bomberman *);
private:
  std::string	_path;
  SDL_Event	event;
  SDL_Window	*_Main_Window;
  SDL_Renderer	*_Main_Renderer;
  Music		*_SoundPlayer;
  int		_select;
  TTF_Font	*_font;
};

void     VideoPlay();

#endif
