//
// PhysicalPlayer.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:59:33 2015 polydo_s
// Last update Tue May 19 16:12:10 2015 polydo_s
//

#ifndef PHYSICAL_PLAYER_HH
#define PHYSICAL_PLAYER_HH

#include <map>
#include <Input.hh>
#include <SdlContext.hh>

#include "APlayer.hh"

class	PhysicalPlayer : public APlayer {

private:
  std::map<int, void(ACharacter::*)(void)>	_actions;
  gdl::Input					_input;

public:
  PhysicalPlayer(float x, float y, ACharacter::eOrientation orientation);

public:
  virtual void	update();
};

#endif
