//
// ACharacter.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun May  3 19:00:09 2015 polydo_s
// Last update Sun May  3 21:25:00 2015 polydo_s
//

#include "ACharacter.hh"

const std::string	ACharacter::getName() const
{
  return this->_name;
}

eOrientation		ACharacter::getOrientation() const
{
  return this->_orientation;
}

void			ACharacter::setOrientation(eOrientation orientation)
{
  this->_orientation = orientation;
}
