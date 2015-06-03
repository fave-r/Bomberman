//
// Fire.hh for Fire.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 17:17:08 2015 clément jean
// Last update Wed Jun  3 16:24:01 2015 Leo Thevenet
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
  static gdl::Geometry _geometry;
  static bool _i;
};

#endif
