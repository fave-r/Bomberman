//
// Bomb.cpp for Bomb.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 02:23:16 2015 clément jean
// Last update Fri Jun  5 02:37:20 2015 clément jean
//

#include "Bomb.hh"

Bomb::Bomb(float x, float y) : AObject(x, y, 0.9, 0.9)
{
  if (this->_model.load("./Assets/Map/bomb.fbx") == false)
    throw std::runtime_error("Cannot load the bomb");
  this->translate(glm::vec3(this->_x, 1, this->_y));
}

Bomb::~Bomb() {}

void                  Bomb::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), GL_QUADS);
}

void	Bomb::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}
