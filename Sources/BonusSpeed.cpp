//
// BonusSpeed.cpp for BonusSpeed.cpp in /home/jean_c/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun  7 18:46:28 2015 clément jean
// Last update Sat Jun 13 18:01:12 2015 clément jean
//

#include "BonusSpeed.hh"

BonusSpeed::BonusSpeed(float x, float y) : ABonus(x, y)
{
  if (this->_model.load("./Assets/Map/bonusSpeed.fbx") == false)
    throw std::runtime_error("Cannot load the speed bonus");
  this->scale(glm::vec3(0.04, 0.04, 0.04));
  this->translate(glm::vec3(x, 1.5, y));
}

BonusSpeed::~BonusSpeed()
{
}

ABonus		*BonusSpeed::create(int x, int y)
{
  return new BonusSpeed(x, y);
}

void		BonusSpeed::affect(std::vector<std::vector<AObject *> > &map, APlayer *player)
{
  this->_SoundPlayer->playSound("BonusS", false);
  player->increaseSpeed();
  map[this->_y][this->_x] = NULL;
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

const std::string             &BonusSpeed::getType() const
{
  static std::string str("2");
  return(str);
}
