//
// main.cpp for Bomberman in /home/polydo_s/rendu/Bomberman
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Fri May 15 13:51:26 2015 polydo_s
// Last update Mon Jun  8 20:44:41 2015 clément jean
//

#include "Menu.hh"

int	main()
{
  Menu          menu;

  try
    {
      VideoPlay();
      menu.initialize();
    }
  catch (const std::runtime_error &e)
    {
      std::cerr << e.what() << std::endl;
      return (EXIT_FAILURE);
    }
  while (menu.update() == true)
  menu.draw();
  return (0);
}
