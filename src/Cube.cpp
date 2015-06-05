//
// Cube.cpp for Cube.cpp in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 19:58:02 2015 clément jean
// Last update Fri Jun  5 02:53:11 2015 clément jean
//

#include "Cube.hh"

Cube::Cube(float x, float y) : AObject(x, y, 0.9, 0.9)
{
}

Cube::~Cube()
{
}

void		Cube::draw(gdl::AShader &shader)
{
  _texture.bind();
  this->_geometry.draw(shader, getTransformation(), GL_QUADS);
}

void          Cube::setModel(const gdl::Geometry &geo)
{
  this->_geometry = geo;
}
