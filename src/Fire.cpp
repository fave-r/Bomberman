//
// Fire.cpp for Fire.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 17:27:42 2015 clément jean
// Last update Sun Jun  7 04:02:55 2015 clément jean
//

#include "Fire.hh"

Fire::Fire(float x, float y) : AObject(x, y, 0.99, 0.99)
{
  if (this->_model.load("./Assets/Map/fire.fbx") == false)
    throw std::runtime_error("Cannot load the bomb");
  //this->translate(glm::vec3(this->_x, 1, this->_y));
}

void		Fire::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), 0.02);
}

void          Fire::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}
