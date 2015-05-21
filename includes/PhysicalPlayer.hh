//
// PhysicalPlayer.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:59:33 2015 polydo_s
// Last update Thu May 21 11:00:51 2015 polydo_s
//

#ifndef PHYSICAL_PLAYER_HH
#define PHYSICAL_PLAYER_HH

#include <map>
#include <Input.hh>
#include <SdlContext.hh>

#include "Bomberman.hh"
#include "APlayer.hh"

class	PhysicalPlayer : public APlayer {

private:
  std::map<int, void(APlayer::*)(void)>	_actions;
  gdl::Input				_input;

public:
  PhysicalPlayer(float, float, APlayer::eOrientation);

public:
  virtual void	update(std::vector<std::vector<AElement *> >);

public:
  void		setInput(const gdl::Input &input);
};

#endif
