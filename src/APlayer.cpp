//
// APlayer.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/src
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:56:39 2015 polydo_s
// Last update Fri May 15 22:08:50 2015 polydo_s
//

#include "APlayer.hh"

APlayer::APlayer() : ACharacter("Player", ACharacter::UP)
{
  static unsigned int id = 1;

  this->_id = id++;
}

void	APlayer::draw() const
{

}

unsigned int	APlayer::getId() const
{
  return this->_id;
}

const std::string	APlayer::ToString() const
{
  return "P";
}
