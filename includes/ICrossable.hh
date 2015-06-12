//
// ICrossable.hh for Bomberman in /home/polydo_s/rendu/Bomberman
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Fri May 29 00:32:40 2015 polydo_s
// Last update Fri Jun 12 01:32:18 2015 polydo_s
//

#ifndef ICROSSABLE_HH
#define ICROSSABLE_HH

#include <vector>

#include "APlayer.hh"

class APlayer;

class	ICrossable {

public:
  virtual void	affect(std::vector<std::vector<AObject *> > &map, APlayer *player) = 0;
};

#endif
