//
// HighScore.hh for HighScore in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Tue Jun  9 15:38:06 2015 Leo Thevenet
// Last update Sat Jun 13 18:52:48 2015 clément jean
//

#ifndef __HIGHSCORE_HH__
#define __HIGHSCORE_HH__

#include "SDL2/SDL_image.h"
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>

#include "Menu.hh"
#include "Score.hh"

class HighScore
{
  SDL_Window			*windows;
  TTF_Font			*_font;
  SDL_Renderer			*_Main_Renderer;
  SDL_Event			_event;
  SDL_Surface			*_backS;
  SDL_Texture			*_backT;
  int				_y;

public:
  HighScore(SDL_Window *, SDL_Renderer *, SDL_Event *);
  HighScore(const int &);
  ~HighScore();

public:
  void				init();
  void				showWinner(const std::string &);
  void				getKey();
  void				showAllScore();
  void				putOneScore(const std::string &str);
};

#endif
