//
// BonusForce.cpp for BonusForce.cpp in /home/jean_c/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Mon Jun  8 01:16:23 2015 clément jean
// Last update Mon Jun  8 01:20:52 2015 clément jean
//

#include "BonusForce.hh"

BonusForce::BonusForce(float x, float y) : ABonus(x, y)
{
  if (this->_model.load("./Assets/Map/bonusDeath.fbx") == false)
    throw std::runtime_error("Cannot load the force bonus");
  this->scale(glm::vec3(0.01, 0.01, 0.01));
  this->translate(glm::vec3(x - 0.2, 1, y - 0.2));
}

BonusForce::~BonusForce()
{
}

void		BonusForce::affect(APlayer &player)
{
  (void)player;
}

void		BonusForce::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), 0.02);
}

void		BonusForce::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}
