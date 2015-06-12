//
// Ground.cpp for Ground.cpp in /home/jean_c/Bomberman/Sources
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri Jun 12 22:45:22 2015 clément jean
// Last update Fri Jun 12 22:45:46 2015 clément jean
//

#include "Ground.hh"

Ground::Ground(float x, float y) : AObject(x, y, 0.9, 0.9)
{
}

void		Ground::draw(gdl::AShader &shader)
{
  _texture.bind();
  this->_geometry.draw(shader, getTransformation(), GL_QUADS);
}

void          Ground::setModel(const gdl::Geometry &geo)
{
  this->_geometry = geo;
}
