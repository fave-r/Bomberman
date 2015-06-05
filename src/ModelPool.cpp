//
// ModelPool.cpp for ModelPool.cpp in /home/jean_c/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri Jun  5 00:17:20 2015 clément jean
// Last update Fri Jun  5 00:27:40 2015 clément jean
//

#include "ModelPool.hh"

ModelPool::ModelPool()
{
}

bool	ModelPool::init()
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
  return true;
}

ModelPool::~ModelPool()
{
}

const gdl::Geometry   &ModelPool::getGeometry() const
{
  return this->_geometry;
}
