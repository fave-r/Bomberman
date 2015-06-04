//
// Box.cpp for Box.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:49:34 2015 clément jean
// Last update Fri Jun  5 00:13:00 2015 polydo_s
//

#include "Box.hh"

Box::Box(float x, float y) : AObject(x, y, 0.9, 0.9)
{
  static bool isInstanciated = false;

  std::cout << "LOLOLO" << std::endl;
  if (!isInstanciated)
    {
      isInstanciated = true;
      Box::_geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      Box::_geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
      Box::_geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
      Box::_geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));

      Box::_geometry.pushUv(glm::vec2(0.0f, 0.0f));
      Box::_geometry.pushUv(glm::vec2(1.0f, 0.0f));
      Box::_geometry.pushUv(glm::vec2(1.0f, 1.0f));
      Box::_geometry.pushUv(glm::vec2(0.0f, 1.0f));

      Box::_geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      Box::_geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
      Box::_geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
      Box::_geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      Box::_geometry.pushUv(glm::vec2(0.0f, 0.0f));
      Box::_geometry.pushUv(glm::vec2(1.0f, 0.0f));
      Box::_geometry.pushUv(glm::vec2(1.0f, 1.0f));
      Box::_geometry.pushUv(glm::vec2(0.0f, 1.0f));

      Box::_geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      Box::_geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
      Box::_geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
      Box::_geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      Box::_geometry.pushUv(glm::vec2(0.0f, 0.0f));
      Box::_geometry.pushUv(glm::vec2(1.0f, 0.0f));
      Box::_geometry.pushUv(glm::vec2(1.0f, 1.0f));
      Box::_geometry.pushUv(glm::vec2(0.0f, 1.0f));

      Box::_geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
      Box::_geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
      Box::_geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
      Box::_geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      Box::_geometry.pushUv(glm::vec2(0.0f, 0.0f));
      Box::_geometry.pushUv(glm::vec2(1.0f, 0.0f));
      Box::_geometry.pushUv(glm::vec2(1.0f, 1.0f));
      Box::_geometry.pushUv(glm::vec2(0.0f, 1.0f));

      Box::_geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
      Box::_geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
      Box::_geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
      Box::_geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
      Box::_geometry.pushUv(glm::vec2(0.0f, 0.0f));
      Box::_geometry.pushUv(glm::vec2(1.0f, 0.0f));
      Box::_geometry.pushUv(glm::vec2(1.0f, 1.0f));
      Box::_geometry.pushUv(glm::vec2(0.0f, 1.0f));

      Box::_geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
      Box::_geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
      Box::_geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
      Box::_geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
      Box::_geometry.pushUv(glm::vec2(0.0f, 0.0f));
      Box::_geometry.pushUv(glm::vec2(1.0f, 0.0f));
      Box::_geometry.pushUv(glm::vec2(1.0f, 1.0f));
      Box::_geometry.pushUv(glm::vec2(0.0f, 1.0f));

      Box::_geometry.build();
    }
}

void	Box::draw(gdl::AShader &shader)
{
  _texture.bind();
  Box::_geometry.draw(shader, getTransformation(), GL_QUADS);
}

void	Box::update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map)
{
  (void)clock;
  (void)map;
}
