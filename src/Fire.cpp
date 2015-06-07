//
// Fire.cpp for Fire.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 17:27:42 2015 clément jean
// Last update Sun Jun  7 17:06:52 2015 clément jean
//

#include "Fire.hh"

Fire::Fire(float x, float y) : AObject(x, y, 0.99, 0.99)
{
  this->scale(glm::vec3(1, 1, 1));
  this->translate(glm::vec3(this->_x, 1, this->_y));
}

void		Fire::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_geometry.draw(shader, getTransformation(), GL_QUADS);
}

void          Fire::setModel(const gdl::Geometry &geo)
{
  this->_geometry = geo;
}
