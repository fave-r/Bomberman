//
// MapGenerator.hh for MapGenerator.hh in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 13:44:50 2015 clément jean
// Last update Tue May 19 23:31:59 2015 polydo_s
//

#ifndef MAP_GENERATOR_HH
#define MAP_GENERATOR_HH

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <ctime>
#include "AElement.hh"
#include "Wall.hh"
#include "Box.hh"
#include "PhysicalPlayer.hh"
#include "ACharacter.hh"

class MapGenerator {

private:
  unsigned int						_width;
  unsigned int						_height;
  std::vector< std::vector<AElement *> >		_map;

public:
  MapGenerator(const unsigned int &width, const unsigned int &height);
  ~MapGenerator();
  const std::vector< std::vector<AElement *> >	&GetMap();

public:
  void				Generate();
  void				Initialize();
};

#endif
