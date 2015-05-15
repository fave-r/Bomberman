//
// AElement.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun May  3 18:55:24 2015 polydo_s
// Last update Fri May 15 18:10:25 2015 polydo_s
//

#include "AElement.hh"

AElement::AElement(float x, float y)
  : _x(x), _y(y)
{

}

float	AElement::getX() const
{
  return this->_x;
}

float	AElement::getY() const
{
  return this->_y;
}

const std::string	AElement::ToString() const
{
  return ".";
}

void	AElement::setPosition(float x, float y)
{
  this->_x = x;
  this->_y = y;
}
