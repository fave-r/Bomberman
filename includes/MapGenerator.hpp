//
// MapGenerator.hpp for MapGenerator.hpp in /home/jean_c/Dropbox/Bomberman-Graphic
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 00:10:24 2015 clément jean
// Last update Fri May 15 13:26:52 2015 clément jean
//

#ifndef __MAPGENERATOR_HPP__
# define __MAPGENERATOR_HPP__

#include <iostream>
#include <cstdlib>

class	MapGenerator
{
private:
  int	_length;
  int	_height;
public:
  MapGenerator(int x, int y)
  {
    this->_length = x;
    this->_height = y;
    std::string	my_map[y];
    int	n = 0;
    int	output;
    while (n < y)
      {
	if (n == 0 || n == y - 1)
	  my_map[n].append(x, 'w');
	else
	  my_map[n].append(x, '.');
	output = 1 + (std::rand() % (int)((x - 1) - 1 + 1));
	my_map[n][0] = 'w';
	my_map[n][x - 1] = 'w';
	my_map[n][output] = 'w';
	output = 1 + (std::rand() % (int)((x - 1) - 1 + 1));
	my_map[n][output] = 'w';
	std::cout << my_map[n] << "\n";
	n++;
      }
  }

  ~MapGenerator()
  {
  }
};

#endif
