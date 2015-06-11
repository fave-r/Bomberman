//
// Box.cpp for Box.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:49:34 2015 clément jean
// Last update Thu Jun 11 16:43:15 2015 polydo_s
//

#include "Box.hh"

Box::Box(float x, float y) : AObject(x, y, 1.0, 1.0)
{

}

Box::~Box() {}

void	Box::destroy(std::vector<std::vector<AObject *> > &map, APlayer *player)
{
  int	x = this->_x;
  int	y = this->_y;

  map[y][x] = NULL;
  player->updateScore(1);
}

void	Box::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_geometry.draw(shader, getTransformation(), GL_QUADS);
}

void	Box::setModel(const gdl::Geometry &geo)
{
  this->_geometry = geo;
}
