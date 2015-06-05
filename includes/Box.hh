//
// Box.hh for Box.hh in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:48:39 2015 clément jean
// Last update Fri Jun  5 02:23:48 2015 clément jean
//

#ifndef __BOX_HH__
# define __BOX_HH__

#include <iostream>
#include <Texture.hh>
#include <Geometry.hh>
#include "AObject.hh"
#include "IUpdatable.hh"

class   Box : public AObject, public IUpdatable
{

private:
  gdl::Geometry	_geometry;

public:
  Box(float, float);
  void	initialize();
  void	setModel(const gdl::Geometry &geo);
public:
  virtual void	draw(gdl::AShader &shader);
  virtual void	update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &);
};

#endif
