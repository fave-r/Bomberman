//
// IUpdatable.hh for Bomberman in /home/polydo_s/rendu/Bomberman
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun May 24 14:08:53 2015 polydo_s
// Last update Fri Jun  5 01:44:47 2015 clément jean
//

#ifndef IUPDATABLE_HH
#define IUPDATABLE_HH

#include <SdlContext.hh>
#include <vector>

#include "AObject.hh"

class IUpdatable {

public:
  virtual void	update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map) = 0;
};

#endif
