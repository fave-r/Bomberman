//
// Menu.cpp for Menu.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 20:34:29 2015 clément jean
// Last update Tue May 19 20:45:32 2015 clément jean
//

#include "Menu.hh"

Menu::Menu()
{
}

Menu::~Menu()
{
}

bool		Menu::initialize()
{
  this->_Main_Window = SDL_CreateWindow("SDL_RenderCopy Example",
				  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1050, 0);
  this->_Main_Renderer = SDL_CreateRenderer(this->_Main_Window, -1, SDL_RENDERER_ACCELERATED);
  this->_path = "./Assets/start_fond.bmp";
  this->_BackGroundS = SDL_LoadBMP(this->_path.c_str());
  this->_BackGroundT = SDL_CreateTextureFromSurface(this->_Main_Renderer, this->_BackGroundS);
  SDL_FreeSurface(this->_BackGroundS);
  return true;
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
	case SDLK_LEFT: case SDLK_RIGHT:
	  _path = (_path == "./Assets/start_fond.bmp") ? "./Assets/options_fond.bmp" : "./Assets/start_fond.bmp";
	  _BackGroundS = SDL_LoadBMP(_path.c_str());
	  _BackGroundT = SDL_CreateTextureFromSurface(_Main_Renderer, _BackGroundS);
	  SDL_FreeSurface(_BackGroundS);
	  break;
	}
      break;
    }
  return true;
}

bool          Menu::Check_Path();
{
  if (this->_path == "./Assets/start_fond.bmp")
    {
      Bomberman       bomberman(20, 20);

      if (bomberman.initialize() == false)
	return false;
      while (bomberman.update() == true)
	bomberman.draw();
    }
  else
    {
      /* /!\ TO IMPLEMENT /!\ */
      _path = "./Assets/start_fond.bmp";
      _BackGroundS = SDL_LoadBMP(this->_path.c_str());
      _BackGroundT = SDL_CreateTextureFromSurface(this->_Main_Renderer, this->_BackGroundS);
      SDL_FreeSurface(this->_BackGroundS);
      return true;
    }
  return false;
}

void          Menu::draw()
{
  SDL_RenderCopy(this->_Main_Renderer, this->_BackGroundT, NULL, NULL);
  SDL_RenderPresent(this->_Main_Renderer);
}

