//
// ABonus.hh for ABonus.hh in /home/jean_c/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Sun Jun  7 17:58:20 2015 clément jean
// Last update Sat Jun 13 18:01:31 2015 clément jean
//

#ifndef __ABONUS_HH__
# define __ABONUS_HH__

#include <BasicShader.hh>
#include <Geometry.hh>
#include <Model.hh>
#include <random>

#include "APlayer.hh"

class ICrossable;

class	ABonus : public ICrossable, public AObject
{
public:
  ABonus(float, float);
  virtual ~ABonus();

public:
  virtual void		affect(std::vector<std::vector<AObject *> > &map, APlayer *player) = 0;
  virtual void          draw(gdl::AShader &shader) = 0;
  virtual void          setModel(const gdl::Geometry &) = 0;

public:
  static ABonus		*createBonus(int x, int y);

protected:
  gdl::Model		_model;
};

#endif
