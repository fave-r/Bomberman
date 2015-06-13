//
// ICrossable.hh for Bomberman in /home/polydo_s/rendu/Bomberman
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Fri May 29 00:32:40 2015 polydo_s
// Last update Sat Jun 13 05:07:22 2015 clément jean
//

#ifndef ICROSSABLE_HH
#define ICROSSABLE_HH

#include <vector>
#include "APlayer.hh"

class	APlayer;

class	ICrossable {

public:
  virtual void	affect(std::vector<std::vector<AObject *> > &map, APlayer *player) = 0;
};

#endif
