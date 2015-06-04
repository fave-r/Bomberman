//
// Cube.cpp for Cube.cpp in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 19:58:02 2015 clément jean
// Last update Fri Jun  5 00:00:37 2015 polydo_s
//

#include "Cube.hh"

Cube::Cube(float x, float y) : AObject(x, y, 0.9, 0.9)
{
  static bool isInstanciated = false;

  if (!isInstanciated)
    {
      Cube::_geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      Cube::_geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
      Cube::_geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
      Cube::_geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  
      Cube::_geometry.pushUv(glm::vec2(0.0f, 0.0f));
      Cube::_geometry.pushUv(glm::vec2(1.0f, 0.0f));
      Cube::_geometry.pushUv(glm::vec2(1.0f, 1.0f));
      Cube::_geometry.pushUv(glm::vec2(0.0f, 1.0f));

      Cube::_geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      Cube::_geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
      Cube::_geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
      Cube::_geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      Cube::_geometry.pushUv(glm::vec2(0.0f, 0.0f));
      Cube::_geometry.pushUv(glm::vec2(1.0f, 0.0f));
      Cube::_geometry.pushUv(glm::vec2(1.0f, 1.0f));
      Cube::_geometry.pushUv(glm::vec2(0.0f, 1.0f));

      Cube::_geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      Cube::_geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
      Cube::_geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
      Cube::_geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      Cube::_geometry.pushUv(glm::vec2(0.0f, 0.0f));
      Cube::_geometry.pushUv(glm::vec2(1.0f, 0.0f));
      Cube::_geometry.pushUv(glm::vec2(1.0f, 1.0f));
      Cube::_geometry.pushUv(glm::vec2(0.0f, 1.0f));

      Cube::_geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
      Cube::_geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
      Cube::_geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
      Cube::_geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      Cube::_geometry.pushUv(glm::vec2(0.0f, 0.0f));
      Cube::_geometry.pushUv(glm::vec2(1.0f, 0.0f));
      Cube::_geometry.pushUv(glm::vec2(1.0f, 1.0f));
      Cube::_geometry.pushUv(glm::vec2(0.0f, 1.0f));

      Cube::_geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
      Cube::_geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
      Cube::_geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
      Cube::_geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
      Cube::_geometry.pushUv(glm::vec2(0.0f, 0.0f));
      Cube::_geometry.pushUv(glm::vec2(1.0f, 0.0f));
      Cube::_geometry.pushUv(glm::vec2(1.0f, 1.0f));
      Cube::_geometry.pushUv(glm::vec2(0.0f, 1.0f));

      Cube::_geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      Cube::_geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      Cube::_geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
      Cube::_geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      Cube::_geometry.pushUv(glm::vec2(0.0f, 0.0f));
      Cube::_geometry.pushUv(glm::vec2(1.0f, 0.0f));
      Cube::_geometry.pushUv(glm::vec2(1.0f, 1.0f));
      Cube::_geometry.pushUv(glm::vec2(0.0f, 1.0f));

      Cube::_geometry.build();
    }
}

Cube::~Cube() {}

void		Cube::draw(gdl::AShader &shader)
{
  _texture.bind();
  Cube::_geometry.draw(shader, getTransformation(), GL_QUADS);
}
