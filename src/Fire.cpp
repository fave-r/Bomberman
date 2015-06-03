//
// Fire.cpp for Fire.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 17:27:42 2015 clément jean
// Last update Wed Jun  3 16:22:40 2015 Leo Thevenet
//

#include "Fire.hh"

bool Fire::_i = false;
gdl::Geometry Fire::_geometry;

Fire::Fire(float x, float y) : AObject(x, y, 0.99, 0.99)
{
}

Fire::~Fire()
{
}

bool		Fire::initialize()
{
  if (this->_i == false)
    {
      this->_i = true;
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
  return true;
}

void		Fire::draw(gdl::AShader &shader)
{
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}

void			Fire::setTexture(const gdl::Texture &old)
{
  this->_texture = old;
}

const std::string	Fire::toString()
{
  return "F";
}
