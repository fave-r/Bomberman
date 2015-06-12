//
// BonusPower.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/src
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Fri Jun 12 01:20:26 2015 polydo_s
// Last update Fri Jun 12 04:06:03 2015 clément jean
//

#include "BonusPower.hh"

BonusPower::BonusPower(float x, float y) : ABonus(x, y)
{
  if (this->_model.load("./Assets/Map/bonusForce.fbx") == false)
    throw std::runtime_error("Cannot load the power bonus");
  this->scale(glm::vec3(0.04, 0.04, 0.04));
  this->translate(glm::vec3(x, 1.5, y));
}

BonusPower::~BonusPower()
{
}

ABonus		*BonusPower::create(int x, int y)
{
  return new BonusPower(x, y);
}

void		BonusPower::affect(std::vector<std::vector<AObject *> > &map, APlayer *player)
{
  this->_SoundPlayer->playSound("BonusF", false);
  player->increasePower();
  map[this->_y][this->_x] = NULL;
}

void		BonusPower::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), 0.02);
}

void		BonusPower::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}
