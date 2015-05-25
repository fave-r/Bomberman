//
// Cube.cpp for Cube.cpp in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 19:58:02 2015 clément jean
// Last update Mon May 25 01:42:07 2015 clément jean
//

#include "Cube.hh"

Cube::Cube(float x, float y) : AObject(x, y)
{

}

Cube::~Cube()
{
}

bool			Cube::initialize()
{
  //  this->_geometry.setColor(glm::vec4(153.0 / 255.0, 51 / 255.0, 0, 1));

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

const gdl::Texture	&Cube::getTexture() const
{
  return this->_texture;
}

const gdl::Geometry	&Cube::getGeometry() const
{
  return this->_geometry;
}

void			Cube::setGeometry(const gdl::Geometry &old)
{
  this->_geometry = old;
}

void			Cube::setTexture(const gdl::Texture &old)
{
  this->_texture = old;
}

bool			Cube::newTexture()
{
  if (this->_texture.load("./Assets/wall.fbm/Wall.tga") == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }
  return true;
}

void		Cube::move(const int &x, const int &y, const int &z)
{
  translate(glm::vec3(x, y, z));
}

void		Cube::draw(gdl::AShader &shader)
{
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}

void          Cube::update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > map)
{
  (void)clock;
  (void)map;
}
