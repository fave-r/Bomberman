//
// Box.cpp for Box.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:49:34 2015 clément jean
// Last update Sun Jun 14 11:54:07 2015 Leo Thevenet
//

#include "Box.hh"

Box::Box(float x, float y) : AObject(x, y, 1.0, 1.0)
{

}

Box::~Box() {}

void			Box::destroy(std::vector<std::vector<AObject *> > &map, APlayer *player)
{
  std::random_device generator;
  std::uniform_int_distribution<int> distribution(1, 10);

  int rand_value = distribution(generator);
  if (rand_value <= 3)
    map[this->_y][this->_x] = ABonus::createBonus(this->_x, this->_y);
  else
    map[this->_y][this->_x] = NULL;
  player->updateScore(1);
}

void			Box::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_geometry.draw(shader, getTransformation(), GL_QUADS);
}

void			Box::setModel(const gdl::Geometry &geo)
{
  this->_geometry = geo;
}

const std::string	&Box::getType() const
{
  static std::string str("B");
  return str;
}
