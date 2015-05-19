//
// APlayer.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:56:12 2015 polydo_s
// Last update Wed May 20 00:08:00 2015 polydo_s
//

#ifndef PLAYER_HH
#define PLAYER_HH

#include "ACharacter.hh"

class	APlayer : public ACharacter {

protected:
  unsigned int	_id;

public:
  APlayer(float, float, ACharacter::eOrientation);

public:
  virtual void	draw() const;

public:
  unsigned int	getId() const;
};

#endif
