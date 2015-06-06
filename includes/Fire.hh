//
// Fire.hh for Fire.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 17:17:08 2015 clément jean
// Last update Sat Jun  6 01:06:16 2015 polydo_s
//

#ifndef __FIRE_HH__
# define __FIRE_HH__

#include <iostream>
#include <Texture.hh>
#include <Geometry.hh>
#include "AObject.hh"
#include "ICrossable.hh"

class	Fire : public AObject, public ICrossable
{

private:
  gdl::Texture		_texture;
  gdl::Geometry		_geometry;

public:
  Fire(float x, float y);

public:
  virtual void	draw(gdl::AShader &shader);

public:
  void          setModel(const gdl::Geometry &);
};

#endif
