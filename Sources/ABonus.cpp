//
// ABonus.cpp for ABonus.cpp in /home/jean_c/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun  7 18:08:50 2015 clément jean
// Last update Sat Jun 13 17:58:42 2015 clément jean
//

#include "ABonus.hh"
#include "BonusPower.hh"
#include "BonusSpeed.hh"
#include "BonusBomb.hh"

ABonus::ABonus(float x, float y) : AObject(x, y, 0.99, 0.99)
{
}

ABonus::~ABonus()
{
}

ABonus		*ABonus::createBonus(int x, int y)
{
  std::random_device			generator;
  std::uniform_int_distribution<int>	distribution(1, 100);
  std::vector<ABonus *(*)(int, int)>	bonus;

  bonus.push_back(&BonusPower::create);
  bonus.push_back(&BonusSpeed::create);
  bonus.push_back(&BonusBomb::create);

  return bonus[distribution(generator) % bonus.size()](x, y);
}
