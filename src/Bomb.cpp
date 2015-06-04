//
// Bomb.cpp for Bomb.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 02:23:16 2015 clément jean
// Last update Thu Jun  4 15:46:08 2015 clément jean
//

#include "Bomb.hh"

Bomb::Bomb(float x, float y) : AObject(x, y, 0.9, 0.9)
{
}

Bomb::~Bomb()
{
}

bool                  Bomb::initialize()
{
  if (this->_model.load("./Assets/Map/bomb.fbx") == false) // EN ATTENDANT DE REGLER LE SETMODEL
    {
      std::cerr << "Cannot load the bomb" << std::endl;
      return (false);
    }
  glm::vec3 v(this->_x, 1, this->_y);
  translate(v);
  return true;
}

void                  Bomb::setTexture(const gdl::Texture &old)
{
  this->_texture = old;
}

void                  Bomb::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), GL_QUADS);
}

const std::string     Bomb::toString()
{
  return "b";
}
