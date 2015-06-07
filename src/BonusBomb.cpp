//
// BonusBomb.cpp for BonusBomb.cpp in /home/jean_c/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Mon Jun  8 01:23:10 2015 clément jean
// Last update Mon Jun  8 01:25:30 2015 clément jean
//

#include "BonusBomb.hh"

BonusBomb::BonusBomb(float x, float y) : ABonus(x, y)
{
  if (this->_model.load("./Assets/Map/bonusBomb.fbx") == false)
    throw std::runtime_error("Cannot load the bomb bonus");
  this->scale(glm::vec3(0.01, 0.01, 0.01));
  this->translate(glm::vec3(x - 0.1, 1, y - 0.1));
}

BonusBomb::~BonusBomb()
{
}

void		BonusBomb::affect(APlayer &player)
{
  (void)player;
}

void		BonusBomb::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), 0.02);
}

void		BonusBomb::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}
