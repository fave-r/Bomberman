//
// Options.hh for Options in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Fri May 29 14:48:51 2015 Leo Thevenet
// Last update Wed Jun  3 01:35:26 2015 polydo_s
//

#ifndef __OPTIONS_HH__
#define __OPTIONS_HH__

#include <SDL2/SDL_ttf.h>
#include <string>

#include "Menu.hh"
#include "Parseur.hh"

class	Options
{
  SDL_Window *windows;
  SDL_Surface *screen;
  TTF_Font *_font;
  SDL_Renderer  *_Main_Renderer;
  SDL_Event	*_event;
  int		select;
  int		x, y, player, densite, ia;
 public:
  Options(SDL_Window *, SDL_Surface *, SDL_Renderer *, SDL_Event *);
  ~Options();
  void FirstView();
  bool getKey();
  void MakeScreen();
  void PutStringOnScreen(SDL_Color, SDL_Rect, std::string, int);
  void MoveCursor(int);
  void ChangeValue(int);
};

#endif
