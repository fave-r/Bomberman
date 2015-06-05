//
// Menu.cpp for Menu.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 20:34:29 2015 clément jean
// Last update Fri Jun  5 02:11:20 2015 clément jean
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
  this->_BackGroundS = IMG_Load(this->_path.c_str());
  this->_BackGroundT = SDL_CreateTextureFromSurface(this->_Main_Renderer, this->_BackGroundS);
  SDL_FreeSurface(this->_BackGroundS);
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
	case SDLK_DOWN: case SDLK_UP:
	  _path = (_path == "./Assets/Menu/start_fond.bmp") ? "./Assets/Menu/options_fond.bmp" : "./Assets/Menu/start_fond.bmp";
	  _BackGroundS = IMG_Load(_path.c_str());
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
