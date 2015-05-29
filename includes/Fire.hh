//
// Fire.hh for Fire.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 17:17:08 2015 clément jean
// Last update Fri May 29 17:37:24 2015 clément jean
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
public:
  Fire(float x, float y);
  ~Fire();

public:
  virtual bool			initialize();
  virtual void			draw(gdl::AShader &shader);
  virtual void			setTexture(const gdl::Texture &old);
  virtual const std::string     toString();

private:
  gdl::Texture		_texture;
  gdl::Geometry		_geometry;
};

#endif
