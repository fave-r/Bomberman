//
// Menu.cpp for Menu.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 20:34:29 2015 clément jean
// Last update Tue Jun  9 11:09:17 2015 Leo Thevenet

#include "Menu.hh"
#include "Options.hh"
#include "SDL2/SDL_image.h"

Menu::Menu()
{
  this->_SoundPlayer = new Music();
}

Menu::~Menu()
{
  if (this->_font)
    TTF_CloseFont(this->_font);
  TTF_Quit();
}

void		Menu::initialize()
{
  this->_SoundPlayer->createSound("./Assets/Sounds/MenuSound.wav", "menu");
  this->_SoundPlayer->playSound("menu", true);
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
    throw std::runtime_error("SDL could not initialize!");
  this->_Main_Window = SDL_CreateWindow("Bomberman",
					SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1050, 0);
  this->_Main_Renderer = SDL_CreateRenderer(this->_Main_Window, -1, SDL_RENDERER_ACCELERATED);
  this->_path = "./Assets/Menu/BackgroundMenu.jpg";
  if (TTF_Init() == -1)
    std::cout << "ttf error" << std::endl;
  if (!(this->_font = TTF_OpenFont("font/simple.ttf", 150)))
    throw std::runtime_error(TTF_GetError());
  this->_select = 0;
  this->_BackGroundS = IMG_Load(this->_path.c_str());
  this->_BackGroundT = SDL_CreateTextureFromSurface(this->_Main_Renderer, this->_BackGroundS);
  SetScreen();
}

void		Menu::SetScreen()
{
  SDL_Rect r;
  SDL_Color fg = {255, 255, 255, 255};
  SDL_Color sl = {255, 55, 55, 255};
  r.x = 300;
  r.y = 250;
  r.w = 500;
  r.h = 180;

  SDL_RenderClear(this->_Main_Renderer);
  SDL_RenderCopy(this->_Main_Renderer, this->_BackGroundT, NULL, NULL);

  PutStringOnScreen((this->_select == 0) ? sl : fg, r, "Jouer");
  r.y += 200;
  r.w += 30;
  PutStringOnScreen((this->_select == 1) ? sl : fg, r, "Charger");
  r.y += 200;
  PutStringOnScreen((this->_select == 2) ? sl : fg, r, "Options");
  r.y += 200;
}

void		Menu::PutStringOnScreen(SDL_Color fg, SDL_Rect r, std::string str)
{
  SDL_Surface *surf = TTF_RenderText_Blended(this->_font, str.c_str(), fg);
  SDL_Texture *_BackGroundT = SDL_CreateTextureFromSurface(this->_Main_Renderer, surf);
  SDL_RenderCopy(this->_Main_Renderer, _BackGroundT, NULL, &r);
  SDL_DestroyTexture(_BackGroundT);
  SDL_FreeSurface(surf);
}

void		Menu::MoveCursor(int where)
{
  this->_select += where;
  this->_select = (this->_select < 0) ? 2 : this->_select;
  this->_select = (this->_select > 2) ? 0 : this->_select;
}

bool		Menu::update()
{
  SDL_WaitEvent(&event);
  switch (event.type)
    {
    case SDL_QUIT:
      return false;//exit(0);
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
	  exit(0);
	case SDLK_RETURN:
	  if (Check_Path() == false)
	    return false;
	  break;
	case SDLK_DOWN:
	  MoveCursor(1);
	  break;
	case SDLK_UP:
	  MoveCursor(-1);
	  break;
	}
      break;
    }
  SetScreen();
  return true;
}

void		Menu::launchBomberman(Bomberman *bomberman)
{
  while (bomberman->update() == true)
    bomberman->draw();
  delete bomberman;
}

bool          Menu::Check_Path()
{
  if (this->_select == 0)
    {
      Bomberman *bomberman = new Bomberman(Parseur::getX(), Parseur::getY(), Parseur::getPlayer());
      delete this->_SoundPlayer;
      SDL_Quit();
      try
	{
	  bomberman->initialize();
	  launchBomberman(bomberman);
	}
      catch (const std::runtime_error &e)
	{
	  std::cerr << e.what() << std::endl;
	  return (false);
	}
    }
  else if (this->_select == 1)
    {
      delete this->_SoundPlayer;
      SDL_Quit();
      try
	{
	  Bomberman *bomberman = new Bomberman(".saved");
	  bomberman->initialize();
	  launchBomberman(bomberman);
	}
      catch (const std::runtime_error &e)
	{
	  std::cerr << e.what() << std::endl;
	  return (false);
	}
    }
  else
    {
      Options *opt = new Options(this->_Main_Window, this->_Main_Renderer, &(this->event));
      opt->FirstView();
      delete opt;
      return true;
    }
  return false;
}

void          Menu::draw()
{
  // SDL_RenderCopy(this->_Main_Renderer, this->_BackGroundT, NULL, NULL);
  SDL_RenderPresent(this->_Main_Renderer);
}
