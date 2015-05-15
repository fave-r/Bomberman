//
// MapGenerator.hh for MapGenerator.hh in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 13:44:50 2015 clément jean
// Last update Fri May 15 14:00:13 2015 polydo_s
//

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <ctime>

class MapGenerator {

private:
  int			_width;
  int			_height;
  std::vector<bool>	_maze;

public:
  MapGenerator(const int &width, const int &height);
  ~MapGenerator();

public:
  void				Generate();
  void				Show();
  void				Initialize();
  void				Carve(const int &x, const int &y);
  const std::vector<bool>	&getMap();
};
