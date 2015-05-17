//
// Bomberman.hh for Bomberman.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Sun May 17 22:34:06 2015 clément jean
// Last update Sun May 17 22:45:07 2015 clément jean
//

#ifndef __BOMBERMAN_HH__
# define __BOMBERMAN_HH__

#include <vector>
#include <list>
#include "APlayer.hh"
#include "AElement.hh"
#include "MapGenerator.hh"

class	Bomberman
{
private:
  std::vector< std::vector<AElement *> >	_map;
  std::list<APlayer *>				_playerlist;

public:
  Bomberman(const unsigned int &x, const unsigned int &y);
  ~Bomberman();

public:
  void	ShowMap();
};

#endif
