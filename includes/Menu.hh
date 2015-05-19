//
// Menu.hh for Menu.hh in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 20:36:11 2015 clément jean
// Last update Tue May 19 20:45:19 2015 clément jean
//

#ifndef __MENU_HH__
# define __MENU_HH__

#include <Game.hh>
#include <SdlContext.hh>
#include <AShader.hh>
#include <BasicShader.hh>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cstdlib>

class Menu : public gdl::Game
{
public:
  Menu();
  ~Menu();
  bool		initialize();
  bool		update();
  bool		Check_Path();
  void		draw();

private:
  std::string	_path;
  SDL_Event	event;
  SDL_Window	*_Main_Window;
  SDL_Renderer	*_Main_Renderer;
  SDL_Surface	*_BackGroundS;
  SDL_Texture	*_BackGroundT;
};

#endif
