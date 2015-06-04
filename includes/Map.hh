//
// Map.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Thu Jun  4 22:37:22 2015 polydo_s
// Last update Thu Jun  4 23:17:44 2015 polydo_s
//

#ifndef GENMAP_HH_
#define GENMAP_HH_

#include <random>
#include <vector>
#include "AObject.hh"
#include "Wall.hh"
#include "Box.hh"
#include "Parseur.hh"
#include "PhysicalPlayer.hh"

class Map {

public:
  static std::vector<std::vector <AObject * > >	generate(unsigned int, unsigned int, unsigned int);
};

#endif
