//
// Wall.cpp for Wall.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:40:10 2015 clément jean
// Last update Fri Jun  5 02:54:06 2015 clément jean
//

#include "Wall.hh"

Wall::Wall(float x, float y) : AObject(x, y, 0.9, 0.9)
{

}

void	Wall::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_geometry.draw(shader, this->getTransformation(), GL_QUADS);
}

void	Wall::setModel(const gdl::Geometry &geo)
{
  this->_geometry = geo;
}
