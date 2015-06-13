//
// Fire.hh for Fire.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 17:17:08 2015 clément jean
// Last update Sat Jun 13 05:13:53 2015 clément jean
//

#ifndef __FIRE_HH__
# define __FIRE_HH__

#include <Geometry.hh>

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
  virtual void          affect(std::vector<std::vector<AObject *> > &map, APlayer *player);
  virtual void		update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map, std::list<APlayer *> &players);

public:
  virtual void		draw(gdl::AShader &shader);

public:
  virtual void          setModel(const gdl::Geometry &);

};

#endif
