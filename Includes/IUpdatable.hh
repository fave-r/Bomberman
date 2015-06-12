//
// IUpdatable.hh for Bomberman in /home/polydo_s/rendu/Bomberman
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun May 24 14:08:53 2015 polydo_s
// Last update Thu Jun 11 16:16:09 2015 polydo_s
//

#ifndef IUPDATABLE_HH
#define IUPDATABLE_HH

#include <SdlContext.hh>
#include <list>
#include <vector>

#include "AObject.hh"
#include "APlayer.hh"

class APlayer;

class IUpdatable {

public:
  virtual void	update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map, std::list<APlayer *> &players) = 0;
};

#endif
