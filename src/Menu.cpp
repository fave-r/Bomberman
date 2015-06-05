//
// Menu.cpp for Menu.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 20:34:29 2015 clément jean
// Last update Fri Jun  5 10:58:21 2015 Leo Thevenet
//

#include "Menu.hh"
#include "Options.hh"
#include "SDL2/SDL_image.h"

Menu::Menu()
{
  //this->_SoundPlayer = new Music();
}

Menu::~Menu()
{
  //delete this->_SoundPlayer;
  if (this->_font)
    TTF_CloseFont(this->_font);
  TTF_Quit();
}

void		Menu::initialize()
{
  //FMOD::Sound	*son;

  //this->_SoundPlayer->createSound(&son, "./Assets/Sounds/MenuSound.wav");
  //this->_SoundPlayer->playSound(son, true);
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
    throw std::runtime_error("SDL could not initialize!");
  this->_Main_Window = SDL_CreateWindow("Bomberman",
					SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1050, 0);
  this->_Main_Renderer = SDL_CreateRenderer(this->_Main_Window, -1, SDL_RENDERER_ACCELERATED);
  this->_path = "./Assets/Menu/start_fond.bmp";
  if (TTF_Init() == -1)
    std::cout << "ttf error" << std::endl;
  if (!(this->_font = TTF_OpenFont("font/simple.ttf", 150)))
    std::cout << TTF_GetError() << std::endl;// balancer exeption
  this->_select = 0;
  SetScreen();
}

void		Menu::SetScreen()
{
  SDL_Rect r;
  SDL_Color fg = {255, 255, 255, 255};
  SDL_Color sl = {255, 55, 55, 255};
  r.x = 300;
  r.y = 300;
  r.w = 500;
  r.h = 180;

  SDL_RenderClear(this->_Main_Renderer);

  SDL_Surface *_BackGroundS = IMG_Load(this->_path.c_str());
  SDL_Texture *_BackGroundT = SDL_CreateTextureFromSurface(this->_Main_Renderer, _BackGroundS);
  SDL_RenderCopy(this->_Main_Renderer, _BackGroundT, NULL, NULL);

  PutStringOnScreen((this->_select == 0) ? sl : fg, r, "Jouer");
  r.y += 200;
  r.w += 30;
  PutStringOnScreen((this->_select == 1) ? sl : fg, r, "Options");
  r.y += 200;
}

void		Menu::PutStringOnScreen(SDL_Color fg, SDL_Rect r, std::string str)
{
  SDL_Surface *surf = TTF_RenderText_Blended(this->_font, str.c_str(), fg);
  SDL_Texture *_BackGroundT = SDL_CreateTextureFromSurface(this->_Main_Renderer, surf);
  SDL_RenderCopy(this->_Main_Renderer, _BackGroundT, NULL, &r);
}

void		Menu::MoveCursor(int where)
{
  this->_select += where;
  this->_select = (this->_select < 0) ? 1 : this->_select;
  this->_select = (this->_select > 1) ? 0 : this->_select;
}

bool		Menu::update()
{
  SDL_WaitEvent(&event);
  switch (event.type)
    {
    case SDL_QUIT:
      exit(0);
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
	  // _path = (_path == "./Assets/Menu/start_fond.bmp") ? "./Assets/Menu/options_fond.bmp" : "./Assets/Menu/start_fond.bmp";
	  // _BackGroundS = IMG_Load(_path.c_str());
	  // _BackGroundT = SDL_CreateTextureFromSurface(_Main_Renderer, _BackGroundS);
	  // SDL_FreeSurface(_BackGroundS);
	  break;
	}
      break;
    }
  SetScreen();
  return true;
}

bool          Menu::Check_Path()
{
  if (this->_select == 0)
    {
      //  delete this->_SoundPlayer;
      SDL_Quit();

      Bomberman *bomberman = new Bomberman(Parseur::getX(), Parseur::getY(), Parseur::getPlayer());
      try
	{
	  bomberman->initialize();
	}
      catch (const std::runtime_error &e)
	{
	  std::cerr << e.what() << std::endl;
	  return (false);
	}

      while (bomberman->update() == true)
	bomberman->draw();
      delete bomberman;
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
