//
// Wall.cpp for Wall.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:40:10 2015 clément jean
// Last update Sun Jun 14 11:58:42 2015 clément jean
//

#include "Wall.hh"

Wall::Wall(float x, float y) : AObject(x, y, 1.0, 1.0)
{

}

void			Wall::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_geometry.draw(shader, this->getTransformation(), GL_QUADS);
}

void			Wall::setModel(const gdl::Geometry &geo)
{
  this->_geometry = geo;
}

const std::string	Wall::getType() const
{
  return("W");
}
