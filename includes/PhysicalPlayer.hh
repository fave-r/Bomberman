//
// PhysicalPlayer.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:59:33 2015 polydo_s
// Last update Sat May 16 00:11:46 2015 clément jean
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

#include <Input.hh>
#include <SdlContext.hh>
#include "APlayer.hh"

class	PhysicalPlayer : public APlayer {

public:
  PhysicalPlayer(float x, float y, ACharacter::eOrientation orientation);

public:
  virtual void	update();

private:
  gdl::Input _input;
};

#endif
