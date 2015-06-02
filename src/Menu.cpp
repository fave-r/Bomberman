//
// Menu.cpp for Menu.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 20:34:29 2015 clément jean
// Last update Tue Jun  2 15:50:30 2015 clément jean
//

#include "Menu.hh"
#include "Options.hh"

Menu::Menu()
{
}

Menu::~Menu()
{
}

bool		Menu::initialize()
{
  Music              test;
  test.createSound(&(this->son), "pokemon.mp3");
  test.playSound(this->son, false);
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      std::cout << "SDL could not initialize!" << std::endl;
      return false;
    }
  else
    { /*faut vérifier les retours*/
      this->_Main_Window = SDL_CreateWindow("Bomberman",
					    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1050, 0);
      this->_Main_Renderer = SDL_CreateRenderer(this->_Main_Window, -1, SDL_RENDERER_ACCELERATED);
      this->_path = "./Assets/Menu/start_fond.bmp";
      this->_BackGroundS = SDL_LoadBMP(this->_path.c_str());
      this->_BackGroundT = SDL_CreateTextureFromSurface(this->_Main_Renderer, this->_BackGroundS);
      SDL_FreeSurface(this->_BackGroundS);
    }
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
	  _path = (_path == "./Assets/Menu/start_fond.bmp") ? "./Assets/Menu/options_fond.bmp" : "./Assets/Menu/start_fond.bmp";
	  _BackGroundS = SDL_LoadBMP(_path.c_str());
	  _BackGroundT = SDL_CreateTextureFromSurface(_Main_Renderer, _BackGroundS);
	  SDL_FreeSurface(_BackGroundS);
	  break;
	}
      break;
    }
  return true;
}

bool          Menu::Check_Path()
{
  if (this->_path == "./Assets/Menu/start_fond.bmp")
    {
      this->son->release();

      Bomberman *bomberman = new Bomberman(Parseur::getX(), Parseur::getY(), Parseur::getPlayer());

      if (bomberman->initialize() == false)
	return false;
      while (bomberman->update() == true)
	bomberman->draw();
      delete bomberman;
    }
  else
    {
      /* /!\ TO IMPLEMENT /!\ */
      // _path = "./Assets/start_fond.bmp";
      // _BackGroundS = SDL_LoadBMP(this->_path.c_str());
      // _BackGroundT = SDL_CreateTextureFromSurface(this->_Main_Renderer, this->_BackGroundS);
      // SDL_FreeSurface(this->_BackGroundS);
      Options *opt = new Options(this->_Main_Window, this->_BackGroundS, this->_Main_Renderer, &(this->event));
      opt->FirstView();
      delete opt;
      return true;
    }
  return false;
}

void          Menu::draw()
{
  SDL_RenderCopy(this->_Main_Renderer, this->_BackGroundT, NULL, NULL);
  SDL_RenderPresent(this->_Main_Renderer);
}
