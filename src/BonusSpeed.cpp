//
// BonusSpeed.cpp for BonusSpeed.cpp in /home/jean_c/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun  7 18:46:28 2015 clément jean
// Last update Mon Jun  8 01:14:38 2015 clément jean
//

#include "BonusSpeed.hh"

BonusSpeed::BonusSpeed(float x, float y) : ABonus(x, y)
{
  if (this->_model.load("./Assets/Map/bonusSpeed.fbx") == false)
    throw std::runtime_error("Cannot load the speed bonus");
  this->scale(glm::vec3(0.01, 0.01, 0.01));
  this->translate(glm::vec3(x - 0.2, 1, y - 0.2));
}

BonusSpeed::~BonusSpeed()
{
}

void		BonusSpeed::affect(APlayer &player)
{
  (void)player;
}

void		BonusSpeed::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), 0.02);
}

void		BonusSpeed::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}
