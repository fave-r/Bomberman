//
// IDestroyable.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun Jun  7 01:30:35 2015 polydo_s
// Last update Sat Jun 13 05:04:40 2015 clément jean
//

#ifndef IDESTROYABLE_HH
#define IDESTROYABLE_HH

#include "APlayer.hh"

class IDestroyable {

 public:
  virtual void	destroy(std::vector<std::vector<AObject *> > &map, APlayer *) = 0;
};

#endif
