//
// Box.cpp for Box.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:49:34 2015 clément jean
// Last update Sun Jun  7 17:28:08 2015 clément jean
//

#include "Box.hh"

Box::Box(float x, float y) : AObject(x, y, 1.0, 1.0)
{

}

Box::~Box() {}

void	Box::destroy(std::vector<std::vector<AObject *> > &map)
{
  int	x = this->_x;
  int	y = this->_y;

  (void)map;
  std::cout << x << ":" << y << std::endl;
  map[y][x] = NULL;
  this->~Box();
}

void	Box::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_geometry.draw(shader, getTransformation(), GL_QUADS);
}

void	Box::update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map)
{
  (void)clock;
  (void)map;
}

void	Box::setModel(const gdl::Geometry &geo)
{
  this->_geometry = geo;
}
