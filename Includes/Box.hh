//
// Box.hh for Box.hh in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:48:39 2015 clément jean
// Last update Sun Jun 14 11:59:06 2015 clément jean
//

#ifndef __BOX_HH__
# define __BOX_HH__

#include <random>
#include <Geometry.hh>

#include "BonusPower.hh"
#include "AObject.hh"
#include "IDestroyable.hh"
#include "IUpdatable.hh"

class IDestroyable;

class Box : public AObject, public IDestroyable
{

private:
  gdl::Geometry				_geometry;

public:
  Box(float, float);
  ~Box();

public:
  virtual void				destroy(std::vector<std::vector<AObject *> > &map, APlayer *);

public:
  virtual void				draw(gdl::AShader &shader);
  virtual const std::string             getType() const;

public:
  void					setModel(const gdl::Geometry &geo);
};

#endif
