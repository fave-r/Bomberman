//
// Box.cpp for Box.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:49:34 2015 clément jean
// Last update Fri Jun  5 02:39:27 2015 clément jean
//

#include "Box.hh"

//static bool isInstanciated = false;


Box::Box(float x, float y) : AObject(x, y, 0.9, 0.9)
{

}

void	Box::initialize()
{
  //  if (!isInstanciated)
  // {
  //  isInstanciated = true;
  /*      this->_geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
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
      //    }*/
}

void	Box::draw(gdl::AShader &shader)
{
  _texture.bind();
  this->_geometry.draw(shader, getTransformation(), GL_QUADS);
}

void	Box::update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map)
{
  (void)clock;
  (void)map;
}

void	Box::setModel(const gdl::Geometry &geo)
{
  this->_geometry = geo;
}
