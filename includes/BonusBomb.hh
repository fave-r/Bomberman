//
// BonusBomb.hh for BonusBomb.hh in /home/jean_c/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Mon Jun  8 01:22:35 2015 clément jean
// Last update Mon Jun  8 01:22:37 2015 clément jean
//

#ifndef __BONUSBOMB_HH__
# define __BONUSBOMN_HH__

#include "ABonus.hh"

class	BonusBomb : public ABonus
{
public:
  BonusBomb(float x, float y);
  virtual ~BonusBomb();

public:
  virtual void          affect(APlayer &player);
  virtual void          draw(gdl::AShader &shader);
  virtual void          setModel(const gdl::Geometry &);
};

#endif
