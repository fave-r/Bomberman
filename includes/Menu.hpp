//
// Menu.cpp for Menu.cpp in /home/jean_c/Graphic
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May  8 00:44:30 2015 clément jean
// Last update Tue May 19 15:41:33 2015 Leo Thevenet
//

#ifndef __MENU_HPP__
# define __MENU_HPP__

#include <Game.hh>
#include <SdlContext.hh>
#include <AShader.hh>
#include <BasicShader.hh>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cstdlib>
#include "GameEngine.hpp"
#include "ShowMap.hpp"

class Menu : public gdl::Game
{
public:
  Menu() {}

  bool	initialize()
  {
    _Main_Window = SDL_CreateWindow("SDL_RenderCopy Example",
				   SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1050, 0);
    _Main_Renderer = SDL_CreateRenderer(_Main_Window, -1, SDL_RENDERER_ACCELERATED);
    _path = "./Assets/start_fond.bmp";
    _BackGroundS = SDL_LoadBMP(_path.c_str());
    _BackGroundT = SDL_CreateTextureFromSurface(_Main_Renderer, _BackGroundS);
    SDL_FreeSurface(_BackGroundS);
    return true;
  }

  bool	update()
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

  bool	Check_Path()
  {
    if (_path == "./Assets/start_fond.bmp")
      {
	Bomberman       bomberman(100, 100);
	// ShowMap engine(100, 100);//GameEngine    engine;

	// if (engine.initialize() == false)
	//   return false;
	// while (engine.update() == true)
	//   engine.draw();
      }
    else
      {
	/* /!\ TO IMPLEMENT /!\ */
	_path = "./Assets/start_fond.bmp";
	_BackGroundS = SDL_LoadBMP(_path.c_str());
	_BackGroundT = SDL_CreateTextureFromSurface(_Main_Renderer, _BackGroundS);
	SDL_FreeSurface(_BackGroundS);
	return true;
      }
    return false;
  }

  void draw()
  {
    SDL_RenderCopy(_Main_Renderer, _BackGroundT, NULL, NULL);
    SDL_RenderPresent(_Main_Renderer);
  }
  ~Menu()
  {
  }
private:
  std::string	_path;
  SDL_Event	event;
  SDL_Window	*_Main_Window;
  SDL_Renderer	*_Main_Renderer;
  SDL_Surface	*_BackGroundS;
  SDL_Texture	*_BackGroundT;
};

#endif
