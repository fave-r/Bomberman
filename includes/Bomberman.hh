//
// Bomberman.hh for Bomberman.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Sun May 17 22:34:06 2015 clément jean
// Last update Tue May 19 15:58:35 2015 polydo_s
//

#ifndef __BOMBERMAN_HH__
# define __BOMBERMAN_HH__

#include <vector>
#include <list>
#include "APlayer.hh"
#include "AElement.hh"
#include "MapGenerator.hh"
#include "Visual.hpp"
#include "GameEngine.hpp"

class	Bomberman
{
private:
  std::vector< std::vector<AElement *> >	_map;
  std::list<APlayer *>			       	_playerlist;

public:
  Bomberman(const unsigned int &x, const unsigned int &y);
  ~Bomberman();

public:
  void	ShowMap();
};

#endif
