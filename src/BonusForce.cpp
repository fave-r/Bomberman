//
// BonusForce.cpp for BonusForce.cpp in /home/jean_c/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Mon Jun  8 01:16:23 2015 clément jean
// Last update Fri Jun 12 04:04:45 2015 clément jean
//

#include "BonusForce.hh"

BonusForce::BonusForce(float x, float y) : ABonus(x, y)
{
  if (this->_model.load("./Assets/Map/bonusForce.fbx") == false)
    throw std::runtime_error("Cannot load the force bonus");
  this->scale(glm::vec3(0.04, 0.04, 0.04));
  this->translate(glm::vec3(x, 1.5, y));
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
