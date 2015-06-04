//
// Fire.cpp for Fire.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 17:27:42 2015 clément jean
// Last update Fri Jun  5 00:01:14 2015 polydo_s
//

#include "Fire.hh"

Fire::Fire(float x, float y) : AObject(x, y, 0.99, 0.99)
{
  static bool isInstanciated = false;

  if (!isInstanciated)
    {
      isInstanciated = true;
      Fire::_geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      Fire::_geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
      Fire::_geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
      Fire::_geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));

      Fire::_geometry.pushUv(glm::vec2(0.0f, 0.0f));
      Fire::_geometry.pushUv(glm::vec2(1.0f, 0.0f));
      Fire::_geometry.pushUv(glm::vec2(1.0f, 1.0f));
      Fire::_geometry.pushUv(glm::vec2(0.0f, 1.0f));

      Fire::_geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      Fire::_geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
      Fire::_geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
      Fire::_geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      Fire::_geometry.pushUv(glm::vec2(0.0f, 0.0f));
      Fire::_geometry.pushUv(glm::vec2(1.0f, 0.0f));
      Fire::_geometry.pushUv(glm::vec2(1.0f, 1.0f));
      Fire::_geometry.pushUv(glm::vec2(0.0f, 1.0f));

      Fire::_geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      Fire::_geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
      Fire::_geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
      Fire::_geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      Fire::_geometry.pushUv(glm::vec2(0.0f, 0.0f));
      Fire::_geometry.pushUv(glm::vec2(1.0f, 0.0f));
      Fire::_geometry.pushUv(glm::vec2(1.0f, 1.0f));
      Fire::_geometry.pushUv(glm::vec2(0.0f, 1.0f));

      Fire::_geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
      Fire::_geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
      Fire::_geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
      Fire::_geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      Fire::_geometry.pushUv(glm::vec2(0.0f, 0.0f));
      Fire::_geometry.pushUv(glm::vec2(1.0f, 0.0f));
      Fire::_geometry.pushUv(glm::vec2(1.0f, 1.0f));
      Fire::_geometry.pushUv(glm::vec2(0.0f, 1.0f));

      Fire::_geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
      Fire::_geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
      Fire::_geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
      Fire::_geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
      Fire::_geometry.pushUv(glm::vec2(0.0f, 0.0f));
      Fire::_geometry.pushUv(glm::vec2(1.0f, 0.0f));
      Fire::_geometry.pushUv(glm::vec2(1.0f, 1.0f));
      Fire::_geometry.pushUv(glm::vec2(0.0f, 1.0f));

      Fire::_geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      Fire::_geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      Fire::_geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
      Fire::_geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      Fire::_geometry.pushUv(glm::vec2(0.0f, 0.0f));
      Fire::_geometry.pushUv(glm::vec2(1.0f, 0.0f));
      Fire::_geometry.pushUv(glm::vec2(1.0f, 1.0f));
      Fire::_geometry.pushUv(glm::vec2(0.0f, 1.0f));

      Fire::_geometry.build();
    }
}

Fire::~Fire() {}

void		Fire::draw(gdl::AShader &shader)
{
  _texture.bind();
  Fire::_geometry.draw(shader, getTransformation(), GL_QUADS);
}
