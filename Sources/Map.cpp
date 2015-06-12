//
// Map.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/src
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Thu Jun  4 22:36:52 2015 polydo_s
// Last update Fri Jun  5 02:21:42 2015 clément jean
//

#include "Map.hh"

std::vector<std::vector<AObject *> >	Map::generate(unsigned int width, unsigned int height, unsigned int players)
{
  std::vector<std::vector<AObject *> > map(height, std::vector<AObject *>(width));
  std::random_device generator;
  std::uniform_int_distribution<int> distribution(1, 100);

  for (unsigned int y = 0; y < height; ++y)
    {
      for (unsigned int x = 0; x < width; ++x)
	{
	  if (!x || !y || x == width - 1 || y == height - 1)
	    map[y][x] = new Wall(x, y);
	  else
	  {
	      int rand_value = distribution(generator);

	      if ((x == 2 && y == 1) || (x == 1 && y == 2))
	  	map[y][x] = NULL;
	      else if ((x == width - 3 && y == height - 2)
	  	       || (x == width - 2 && y == height - 3))
	  	map[y][x] = NULL;
	      else if (rand_value > (100 - Parseur::getDensite()) && !dynamic_cast<Wall *>(map[y][x - 1]) &&
		       !dynamic_cast<Wall *>(map[y - 1][x + 1]))
		  map[y][x] = new Wall(x, y);
	      else
		map[y][x] = new Box(x, y);
	  }
	}
    }

  map[1][1] = NULL;
  if (players == 2)
    map[height - 2][width - 2] = NULL;
  return (map);
}
