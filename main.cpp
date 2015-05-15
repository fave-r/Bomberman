//
// main.cpp for Bomberman in /home/polydo_s/rendu/Bomberman
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Fri May 15 13:51:26 2015 polydo_s
// Last update Fri May 15 22:24:07 2015 clément jean
//

#include <iostream>

#include "MapGenerator.hh"

int	main(int ac, char *av[])
{
  if (ac != 3)
    {
      std::cerr << "You need to pass a width and height for the map" << std::endl;
      return (1);
    }
  else
    {
      MapGenerator *map = new MapGenerator(std::stoi(av[1]), std::stoi(av[2]));
      map->Generate();
      map->Show();
    }
  return (0);
}
