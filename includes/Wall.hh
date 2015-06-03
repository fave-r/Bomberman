//
// Wall.hh for Wall.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 17:25:07 2015 clément jean
// Last update Wed Jun  3 16:12:59 2015 Leo Thevenet
//

#ifndef __WALL_HH__
# define __WALL_HH__

#include <iostream>
#include <Texture.hh>
#include <Geometry.hh>
#include "AObject.hh"

class   Wall : public AObject
{
public:
  Wall(float x, float y);
  ~Wall();

public:
  virtual void	draw(gdl::AShader &shader);
  virtual bool  initialize();

public:
  virtual const std::string	toString();

public:
  virtual void  setTexture(const gdl::Texture &old);

private:
  gdl::Texture  _texture;
  static gdl::Geometry _geometry;
  static bool _i;
};

#endif
