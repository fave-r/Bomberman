//
// Fire.hh for Fire.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 17:17:08 2015 clément jean
// Last update Wed Jun 10 00:18:38 2015 polydo_s
//

#ifndef __FIRE_HH__
# define __FIRE_HH__

#include <iostream>
#include <Texture.hh>
#include <Geometry.hh>

#include "AObject.hh"
#include "APlayer.hh"
#include "IUpdatable.hh"
#include "ICrossable.hh"

class	Fire : public AObject, public ICrossable, public IUpdatable
{

private:
  gdl::Geometry		_geometry;
  double		_elapsed;
  float			_livespan;

public:
  Fire(float x, float y, double elapsed);
  ~Fire();

public:
  virtual void          affect(APlayer *player);
  virtual void		update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map);

public:
  virtual void		draw(gdl::AShader &shader);

public:
  virtual void          setModel(const gdl::Geometry &);

};

#endif
