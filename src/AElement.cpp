//
// AElement.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun May  3 18:55:24 2015 polydo_s
// Last update Sun May  3 21:24:57 2015 polydo_s
//

#include "AElement.hh"

int	AElement::getX() const
{
  return this->_x;
}

int	AElement::getY() const
{
  return this->_y;
}

void	AElement::setPosition(unsigned int x, unsigned int y)
{
  this->_x = x;
  this->_y = y;
}
