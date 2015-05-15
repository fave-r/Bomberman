//
// AElement.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun May  3 18:55:24 2015 polydo_s
// Last update Fri May 15 17:11:40 2015 polydo_s
//

#include "AElement.hh"

float	AElement::getX() const
{
  return this->_x;
}

float	AElement::getY() const
{
  return this->_y;
}

const std::string	&toString() const
{
  return ".";
}

void	AElement::setPosition(float x, float y)
{
  this->_x = x;
  this->_y = y;
}
