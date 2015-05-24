//
// APlayer.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/src
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:56:39 2015 polydo_s
// Last update Sun May 24 14:21:24 2015 polydo_s
//

#include "APlayer.hh"

APlayer::APlayer(float x, float y, APlayer::eOrientation orientation)
  : AObject(x, y), _orientation(orientation)
{
  static unsigned id = 1;
  this->_id = id++;
}

void			APlayer::draw() const
{

}

void			APlayer::move(eOrientation orientation)
{
  this->_orientation = orientation;
}

void			APlayer::goUp()
{
  std::cout << "UP" << std::endl;
}

void			APlayer::goRight()
{
  std::cout << "RIGHT" << std::endl;
}

void			APlayer::goDown()
{
  std::cout << "DOWN" << std::endl;
}

void			APlayer::goLeft()
{
  std::cout << "LEFT" << std::endl;
}


unsigned int		APlayer::getId() const
{
  return this->_id;
}

APlayer::eOrientation	APlayer::getOrientation() const
{
  return this->_orientation;
}

void			APlayer::setOrientation(eOrientation orientation)
{
  this->_orientation = orientation;
}
