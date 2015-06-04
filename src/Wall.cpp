//
// Wall.cpp for Wall.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:40:10 2015 clément jean
// Last update Fri Jun  5 00:12:49 2015 polydo_s
//

#include "Wall.hh"

Wall::Wall(float x, float y) : AObject(x, y, 0.9, 0.9)
{
  static bool isInstanciated = false;

  std::cout << "LALALA" << std::endl;
  if (!isInstanciated)
    {
      isInstanciated = true;

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
}

void	Wall::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_geometry.draw(shader, this->getTransformation(), GL_QUADS);
}
