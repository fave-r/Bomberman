//
// Map.hh for Bomberman in /home/polydo_s/rendu/Bomberman
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sat Jun 13 19:11:06 2015 polydo_s
// Last update Sun Jun 14 03:01:01 2015 polydo_s
//

#ifndef MAP_HH_
#define MAP_HH_

#include <random>
#include <vector>

#include "AObject.hh"
#include "Wall.hh"
#include "Box.hh"
#include "Parseur.hh"
#include "PhysicalPlayer.hh"
#include "ArtificialPlayer.hh"
#include "ModelPool.hh"

class Map {

public:
  static std::list<APlayer *> spawnPlayers(std::vector<std::vector<AObject *> > &map);
  static std::vector<std::vector <AObject * > > generate();
};

#endif
