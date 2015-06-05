//
// Fire.cpp for Fire.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 17:27:42 2015 clément jean
// Last update Fri Jun  5 02:30:58 2015 clément jean
//

#include "Fire.hh"

Fire::Fire(float x, float y) : AObject(x, y, 0.99, 0.99)
{
  this->_geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  this->_geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));

  this->_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  this->_geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  this->_geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  this->_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  this->_geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  this->_geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  this->_geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  this->_geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  this->_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  this->_geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  this->_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  this->_geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  this->_geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  this->_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  this->_geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  this->_geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  this->_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  this->_geometry.build();
}

Fire::~Fire() {}

void		Fire::draw(gdl::AShader &shader)
{
  _texture.bind();
  this->_geometry.draw(shader, getTransformation(), GL_QUADS);
}

void          Fire::setModel(const gdl::Geometry &geo)
{
  this->_geometry = geo;
}
