//
// Box.cpp for Box.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:49:34 2015 clément jean
<<<<<<< HEAD
// Last update Wed Jun 10 00:03:40 2015 polydo_s
=======
// Last update Mon Jun  8 15:52:09 2015 clément jean
>>>>>>> ec6aa9191970d65097f2e549208f53e0c22de69a
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

  map[y][x] = NULL;
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
