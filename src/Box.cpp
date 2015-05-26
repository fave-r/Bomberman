//
// Box.cpp for Box.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:49:34 2015 clément jean
// Last update Tue May 26 02:17:13 2015 clément jean
//

#include "Box.hh"

Box::Box(float x, float y) : AObject(x, y)
{
}

Box::~Box()
{
}

void	Box::draw(gdl::AShader &shader)
{
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}

void	Box::update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > map)
{
  (void)clock;
  (void)map;
}

bool	Box::initialize()
{
  this->_geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  this->_geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));

  this->_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  //this->_geometry.setColor(glm::vec4(153.0 / 255.0, 51 / 255.0, 0, 1));
  this->_geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  this->_geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  this->_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  //this->_geometry.setColor(glm::vec4(153.0 / 255.0, 51 / 255.0, 0, 1));
  this->_geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  this->_geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  this->_geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  this->_geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  this->_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  //this->_geometry.setColor(glm::vec4(153.0 / 255.0, 51 / 255.0, 0, 1));
  this->_geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  this->_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  //this->_geometry.setColor(glm::vec4(0, 1, 0, 1));
  this->_geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  this->_geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  this->_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  //this->_geometry.setColor(glm::vec4(153.0 / 255.0, 51 / 255.0, 0, 1));
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
/*
bool                    Box::newTexture()
{
  if (this->_texture.load("./Assets/box.fbm/box.tga") == false)
    {
      std::cerr << "Cannot load the box texture" << std::endl;
      return (false);
    }
  return true;
}
*/
void          Box::setTexture(const gdl::Texture &old)
{
  this->_texture = old;
}
