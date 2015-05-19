//
// main.cpp for Bomberman in /home/polydo_s/rendu/Bomberman
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Fri May 15 13:51:26 2015 polydo_s
// Last update Tue May 19 19:29:24 2015 Leo Thevenet
//

#include <iostream>

#include "Bomberman.hh"

#include "Menu.hpp"
#include "GameEngine.hpp"

int	main(int ac, char *av[])
{
  if (ac != 3)
    {
      std::cerr << "You need to pass a width and height for the map" << std::endl;
      return (1);
    }
  else
    {
      Menu          menu;

      if (menu.initialize() == false)
	return (EXIT_FAILURE);
      while (menu.update() == true)
	menu.draw();
      av = av;
      //Bomberman	bomberman(std::stoi(av[1]), std::stoi(av[2]));
    }
  return (0);
}
