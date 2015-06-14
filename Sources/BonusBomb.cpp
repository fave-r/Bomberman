//
// BonusBomb.cpp for BonusBomb.cpp in /home/jean_c/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Mon Jun  8 01:23:10 2015 clément jean
// Last update Sun Jun 14 11:56:57 2015 clément jean
//

#include "BonusBomb.hh"

BonusBomb::BonusBomb(float x, float y) : ABonus(x, y)
{
  if (this->_model.load("./Assets/Map/bonusBomb.fbx") == false)
    throw std::runtime_error("Cannot load the bomb bonus");
  this->scale(glm::vec3(0.03, 0.03, 0.03));
  this->translate(glm::vec3(x, 1.5, y));
  if (this->_model.createSubAnim(0, "rotate", 0, 36) == false)
    throw std::runtime_error("Can't load bonus bomb's animation");
  this->_model.setCurrentSubAnim("rotate");
}

BonusBomb::~BonusBomb()
{
}

ABonus			*BonusBomb::create(int x, int y)
{
  return new BonusBomb(x, y);
}

void			BonusBomb::affect(std::vector<std::vector<AObject *> > &map, APlayer *player)
{
  this->_SoundPlayer->playSound("BonusB", false);
  player->increaseMaxBombs();
  map[this->_y][this->_x] = NULL;
}

void			BonusBomb::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), 0.02);
}

void			BonusBomb::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}

const std::string	BonusBomb::getType() const
{
  return("1");
}
