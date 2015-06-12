//
// Options.cpp for Options in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Fri May 29 14:48:30 2015 Leo Thevenet
// Last update Fri Jun 12 22:11:46 2015 clément jean
//

#include "Options.hh"
#include "SDL2/SDL_image.h"

Options::Options(SDL_Window *windows, SDL_Renderer *_Main_Renderer, SDL_Event *event)
{
  if (TTF_Init() == -1)
    throw loading_error("HighScore : TTF error");
  if (!(this->_font = TTF_OpenFont("Ressources/font/simple.ttf", 150)))
    throw loading_error(TTF_GetError());
  this->windows = windows;
  this->_Main_Renderer = _Main_Renderer;
  this->_event = event;
  this->select = 0;
  this->x = Parseur::getX();
  this->y = Parseur::getY();
  this->player = Parseur::getPlayer();
  this->densite = Parseur::getDensite();
  this->ia = Parseur::getIA();;
  this->_backS = IMG_Load("./Assets/Menu/BackgroundMenu.jpg");
  this->_backT = SDL_CreateTextureFromSurface(this->_Main_Renderer, this->_backS);
}

Options::~Options()
{
  SDL_DestroyTexture(this->_backT);
  SDL_FreeSurface(this->_backS);
  if (this->_font)
    TTF_CloseFont(this->_font);
  TTF_Quit();
}

void Options::MakeScreen()
{
  SDL_Rect r;
  SDL_Color fg = {255, 255, 255, 255};
  SDL_Color sl = {255, 55, 55, 255};
  r.x = 150;
  r.y = 50;
  r.w = 1100;
  r.h = 130;
  SDL_RenderClear(this->_Main_Renderer);
  SDL_RenderCopy(this->_Main_Renderer, this->_backT, NULL, NULL);

  PutStringOnScreen((this->select == 0) ? sl : fg, r, "Largeur X    -> ", this->x);
  r.y += 150;
  PutStringOnScreen((this->select == 1) ? sl : fg, r, "Longueur Y   -> ", this->y);
  r.y += 150;
  PutStringOnScreen((this->select == 2) ? sl : fg, r, "Mode de jeu -> ", this->player);
  r.y += 150;
  PutStringOnScreen((this->select == 3) ? sl : fg, r, "IA                  -> ", this->ia);
  r.y += 150;
  PutStringOnScreen((this->select == 4) ? sl : fg, r, "Densite         -> ", this->densite);
  r.y += 200;
  r.x = 500;
  r.w = 450;
  PutStringOnScreen((this->select == 5) ? sl : fg, r, "Sauvegarder", -1);
  SDL_RenderPresent(this->_Main_Renderer);
}

void Options::PutStringOnScreen(SDL_Color fg, SDL_Rect r, std::string str, int nb)
{
  str += (nb == -1) ? "" : std::to_string(nb);
  SDL_Surface *surf = TTF_RenderText_Blended(this->_font, str.c_str(), fg);
  SDL_Texture *_BackGroundT = SDL_CreateTextureFromSurface(this->_Main_Renderer, surf);
  SDL_RenderCopy(this->_Main_Renderer, _BackGroundT, NULL, &r);
  SDL_DestroyTexture(_BackGroundT);
  SDL_FreeSurface(surf);
}

void Options::FirstView()
{
  MakeScreen();
  while (getKey())
    MakeScreen();
}

void Options::MoveCursor(int where)
{
  this->select += where;
  this->select = (this->select < 0) ? 5 : this->select;
  this->select = (this->select > 5) ? 0 : this->select;
}

void Options::ChangeValue(int nb)
{
  if (this->select == 0)
    this->x += (this->x + nb < 10) ? 0 : nb;
  else if (this->select == 1)
    this->y += (this->y + nb < 10) ? 0 : nb;
  else if (this->select == 2)
    this->player += (this->player + nb < 1) ? 0 : (this->player + nb > 2) ? 0 : nb;
  else if (this->select == 3)
    this->ia += (this->ia + nb < 0) ? 0 : nb;
  else if (this->select == 4)
    this->densite += (this->densite + nb < 0) ? 0 : (this->densite + nb > 80) ? 0 : nb;
}

bool Options::getKey()
{
  SDL_Joystick *aa = SDL_JoystickOpen(0);
  int a = 10000;

  if (SDL_JoystickGetButton(aa, 4) == 1)
    MoveCursor(-1);
  else if (SDL_JoystickGetButton(aa, 6) == 1)
    MoveCursor(1);
  else if (SDL_JoystickGetButton(aa, 5) == 1)
    ChangeValue(1);
  else if (SDL_JoystickGetButton(aa, 7) == 1)
    ChangeValue(-1);
  else if (SDL_JoystickGetButton(aa, 14) == 1)
    {
      if (this->select == 5)
	{
	  Parseur::setConf(this->x, this->y, this->player, this->ia, this->densite);
	  return false;
	}
    }
  else
    a = 0;
  usleep(a);

  SDL_WaitEvent(this->_event);
  switch ((*this->_event).type)
    {
    case SDL_QUIT:
      return false;
    case SDL_KEYDOWN:
      switch ((*this->_event).key.keysym.sym)
	{
	case SDLK_ESCAPE:
	  return false;
	case SDLK_RETURN:
	  if (this->select == 5)
	    {
	      Parseur::setConf(this->x, this->y, this->player, this->ia, this->densite);
	      return false;
	    }
	  break;
	case SDLK_LEFT:
	  ChangeValue(-1);
	  break;
	case SDLK_RIGHT:
	  ChangeValue(1);
	  break;
	case SDLK_UP:
	  MoveCursor(-1);
	  break;
	case SDLK_DOWN:
	  MoveCursor(1);
	  break;
	default:
	  break;
	}
    default:
      break;
    }
  return true;
}
