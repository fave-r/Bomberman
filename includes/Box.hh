//
// Box.hh for Box.hh in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:48:39 2015 clément jean
// Last update Sun Jun  7 16:59:40 2015 polydo_s
//

#ifndef __BOX_HH__
# define __BOX_HH__

#include <iostream>
#include <Texture.hh>
#include <Geometry.hh>

#include "AObject.hh"
#include "IDestroyable.hh"
#include "IUpdatable.hh"

class Box : public AObject, public IUpdatable, public IDestroyable
{

private:
  gdl::Geometry	_geometry;

public:
  Box(float, float);
  ~Box();

public:
  virtual void	destroy(std::vector<std::vector<AObject *> > &map);

public:
  virtual void	draw(gdl::AShader &shader);
  virtual void	update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &);

public:
  void		setModel(const gdl::Geometry &geo);
};

#endif
