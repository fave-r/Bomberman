//
// ICrossable.hh for Bomberman in /home/polydo_s/rendu/Bomberman
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Fri May 29 00:32:40 2015 polydo_s
// Last update Sun Jun  7 18:01:44 2015 clément jean
//

#ifndef ICROSSABLE_HH
#define ICROSSABLE_HH

#include "APlayer.hh"

class APlayer;

class	ICrossable {

public:
  virtual void	affect(APlayer &player) = 0;
};

#endif
