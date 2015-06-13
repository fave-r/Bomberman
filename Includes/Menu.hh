//
// Menu.hh for Menu.hh in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 20:36:11 2015 clément jean
// Last update Sat Jun 13 18:29:32 2015 clément jean
//

#ifndef __MENU_HH__
# define __MENU_HH__

#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <cstdlib>
#include <dirent.h>
#include <unistd.h>

#include "Bomberman.hh"
#include "Music.hh"

class Menu
{
public:
  Menu();
  ~Menu();

public:
  void				initialize();
  bool				update();
  bool				Check_Path();
  void				draw();
  void				SetScreen();
  void				PutStringOnScreen(const SDL_Color &, const SDL_Rect &, const std::string &);
  void				MoveCursor(int);
  void				launchBomberman(Bomberman *&);
  void				GetAllMap();
  void				MoveForLoad(int);

private:
  std::string			_path;
  SDL_Event			event;
  SDL_Window			*_Main_Window;
  SDL_Renderer			*_Main_Renderer;
  Music				*_SoundPlayer;
  int				_select;
  int				_selectMap;
  TTF_Font			*_font;
  SDL_Surface			*_BackGroundS;
  SDL_Texture			*_BackGroundT;
  std::vector<std::string>	_allMap;
};

void				VideoPlay();

#endif
