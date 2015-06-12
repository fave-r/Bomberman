//
// BonusSpeed.hh for BonusSpeed.hh in /home/jean_c/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun  7 18:36:08 2015 clément jean
// Last update Fri Jun 12 02:42:59 2015 polydo_s
//

#ifndef __BONUSSPEED_HH__
# define __BONUSSPEED_HH__

#include "ABonus.hh"

class	BonusSpeed : public ABonus
{
public:
  BonusSpeed(float x, float y);
  virtual ~BonusSpeed();

public:
  static ABonus		*create(int x, int y);

public:
  virtual void          affect(std::vector<std::vector<AObject *> > &map, APlayer *player);
  virtual void          draw(gdl::AShader &shader);
  virtual void          setModel(const gdl::Geometry &);
};

#endif
