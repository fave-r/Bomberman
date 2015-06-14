//
// BonusBomb.hh for BonusBomb.hh in /home/jean_c/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Mon Jun  8 01:22:35 2015 clément jean
// Last update Sun Jun 14 12:01:22 2015 clément jean
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
  static ABonus				*create(int x, int y);

public:
  virtual void				affect(std::vector<std::vector<AObject *> > &map, APlayer *player);
  virtual void				draw(gdl::AShader &shader);
  virtual void				setModel(const gdl::Geometry &);
  virtual const std::string             getType() const;
};

#endif
