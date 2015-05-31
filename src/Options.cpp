//
// Options.cpp for Options in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Fri May 29 14:48:30 2015 Leo Thevenet
// Last update Sun May 31 15:21:45 2015 Leo Thevenet
//

#include "Options.hh"

Options::Options(SDL_Window *windows, SDL_Surface *screen, SDL_Renderer *_Main_Renderer, SDL_Event *event)
{
  if (TTF_Init() == -1)
    std::cout << "ttf error" << std::endl;
  if (!(this->_font = TTF_OpenFont("font/BebasNeue.otf", 150)))
    std::cout << TTF_GetError() << std::endl;// balancer exeption
  this->windows = windows;
  this->screen = screen;
  this->_Main_Renderer = _Main_Renderer;
  this->_event = event;
  this->select = 0;
  this->x = Parseur::getX();
  this->y = Parseur::getY();
  this->player = Parseur::getPlayer();
  this->densite = Parseur::getDensite();
}

Options::~Options()
{
  if (this->_font)
    TTF_CloseFont(this->_font);
  TTF_Quit();
}

void Options::MakeScreen()
{
  SDL_Rect r;
  SDL_Color fg = {255, 255, 255, 255};
  SDL_Color sl = {255, 55, 55, 255};
  r.x = 600;
  r.y = 100;
  r.w = 700;
  r.h = 150;
  SDL_RenderClear(this->_Main_Renderer);

  PutStringOnScreen((this->select == 0) ? sl : fg, r, "Largeur X ->  ", this->x);
  r.y += 150;
  PutStringOnScreen((this->select == 1) ? sl : fg, r, "Longueur Y -> ", this->y);
  r.y += 150;
  PutStringOnScreen((this->select == 2) ? sl : fg, r, "Joueurs ->    ", this->player);
  r.y += 150;
  PutStringOnScreen((this->select == 3) ? sl : fg, r, "Densite ->    ", this->densite);
  r.y += 300;
  r.x = 750;
  r.w = 450;
  PutStringOnScreen((this->select == 4) ? sl : fg, r, "Sauvegarder", -1);
  SDL_RenderPresent(this->_Main_Renderer);
}

void Options::PutStringOnScreen(SDL_Color fg, SDL_Rect r, std::string str, int nb)
{
  str += (nb == -1) ? "" : std::to_string(nb);
  SDL_Surface *surf = TTF_RenderText_Blended(this->_font, str.c_str(), fg);
  SDL_Texture *_BackGroundT = SDL_CreateTextureFromSurface(this->_Main_Renderer, surf);
  SDL_RenderCopy(this->_Main_Renderer, _BackGroundT, NULL, &r);
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
  this->select = (this->select < 0) ? 4 : this->select;
  this->select = (this->select > 4) ? 0 : this->select;
}

void Options::ChangeValue(int nb)
{
  if (this->select == 0)
    this->x += (this->x + nb < 10) ? 0 : nb;
  else if (this->select == 1)
    this->y += (this->y + nb < 10) ? 0 : nb;
  else if (this->select == 2)
    this->player += (this->player + nb < 1) ? 0 : nb;
  else if (this->select == 3)
    this->densite += (this->densite + nb < 0) ? 0 : (this->densite + nb > 80) ? 0 : nb;
}

bool Options::getKey()
{
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
	  if (this->select == 4)
	    {
	      Parseur::setConf(this->x, this->y, this->player, this->densite);
	      return false;
	    }
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
	}
      break;
    }
  return true;
}
