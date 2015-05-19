//
// PhysicalPlayer.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:59:33 2015 polydo_s
// Last update Mon May 18 11:24:14 2015 polydo_s
//

#ifndef PHYSICAL_PLAYER_HH
#define PHYSICAL_PLAYER_HH

/**
 * @class PhysicalPlayer
 * @brief A human controlled player
 *
 * The action are decided based on user's
 * inputs
 *
 * @author Swann Polydor (polydo_s)
 * @version 0.1
 * @bug No known bugs.
 *
 * @date May 5, 2015
 */

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
