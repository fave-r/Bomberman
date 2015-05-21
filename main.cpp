//
// main.cpp for Bomberman in /home/polydo_s/rendu/Bomberman
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Fri May 15 13:51:26 2015 polydo_s
// Last update Thu May 21 16:26:53 2015 Leo Thevenet
//

#include "Menu.hh"

int	main()
{
  Menu          menu;

  if (menu.initialize() == false)
    return (EXIT_FAILURE);
  while (menu.update() == true)
    menu.draw();
  return (0);
}
