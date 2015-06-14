//
// BonusPower.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Fri Jun 12 01:19:36 2015 polydo_s
// Last update Sun Jun 14 12:01:01 2015 clément jean
//


#ifndef __BONUSPOWER_HH__
# define __BONUSPOWER_HH__

#include "ABonus.hh"

class	BonusPower : public ABonus
{
public:
  BonusPower(float x, float y);
  virtual ~BonusPower();

public:
  static ABonus				*create(int x, int b);

public:
  virtual void				affect(std::vector<std::vector<AObject *> > &map, APlayer *player);
  virtual void				draw(gdl::AShader &shader);
  virtual void				setModel(const gdl::Geometry &);
  virtual const std::string             getType() const;
};

#endif
