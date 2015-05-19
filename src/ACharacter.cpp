//
// ACharacter.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun May  3 19:00:09 2015 polydo_s
// Last update Mon May 18 11:21:53 2015 polydo_s
//

#include "ACharacter.hh"

ACharacter::ACharacter(float x, float y, ACharacter::eOrientation orientation)
  : AElement(x, y)
{
  this->_orientation = orientation;
}

void			ACharacter::move(eOrientation orientation)
{
  this->_orientation = orientation;
}

void			ACharacter::goUp()
{
  std::cout << "UP" << std::endl;
}

void			ACharacter::goRight()
{
  std::cout << "RIGHT" << std::endl;
}

void			ACharacter::goDown()
{
  std::cout << "DOWN" << std::endl;
}

void			ACharacter::goLeft()
{
  std::cout << "LEFT" << std::endl;
}

ACharacter::eOrientation	ACharacter::getOrientation() const
{
  return this->_orientation;
}

void			ACharacter::setOrientation(eOrientation orientation)
{
  this->_orientation = orientation;
}
