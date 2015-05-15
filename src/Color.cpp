//
// Color.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 18:19:08 2015 polydo_s
// Last update Tue May  5 19:49:54 2015 polydo_s
//

#include "Color.hh"

Color::Color(unsigned char r, unsigned char g, unsigned char b, float a=1)
  : _r(r), _g(g), _b(b), _a(a)
{
  if (this->_a < 0)
    this->_a = 0;
  if (this->_a > 1.0)
    this->_a = 1.0;
}

unsigned char  	Color::getR() const
{
  return this->_r;
}

unsigned char  	Color::getG() const
{
  return this->_g;
}

unsigned char  	Color::getB() const
{
  return this->_b;
}

float	       	Color::getAlpha() const
{
  return this->_a;
}

uint32_t       	Color::getRGBA() const
{
  return this->_r << 24 | this->_g << 16 | this->_b << 8 | (int)(this->_a * 255);
}
