//
// BonusForce.hh for BonusForce.hh in /home/jean_c/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Mon Jun  8 01:17:33 2015 clément jean
// Last update Mon Jun  8 01:18:17 2015 clément jean
//

#ifndef __BONUSFORCE_HH__
# define __BONUSFORCE_HH__

#include "ABonus.hh"

class	BonusForce : public ABonus
{
public:
  BonusForce(float x, float y);
  virtual ~BonusForce();

public:
  virtual void          affect(APlayer &player);
  virtual void          draw(gdl::AShader &shader);
  virtual void          setModel(const gdl::Geometry &);
};

#endif
