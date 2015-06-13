//
// Map.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Thu Jun  4 22:37:22 2015 polydo_s
// Last update Sat Jun 13 04:50:08 2015 clément jean
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
#include "ModelPool.hh"

namespace Map {
  std::vector<std::vector <AObject * > >	generate(unsigned int, unsigned int, unsigned int);
};

#endif
