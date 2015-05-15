//
// APlayer.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/src
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:56:39 2015 polydo_s
// Last update Fri May 15 16:59:22 2015 polydo_s
//

#include "APlayer.hh"

Player::Player()
{
  static unsigned int id = 1;

  this->_id = id++;
}

void	PhysicalPlayer::draw() const
{

}

unsigned int	Player::getId() const
{
  return this->_id;
}
