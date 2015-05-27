//
// Wall.hh for Wall.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 17:25:07 2015 clément jean
// Last update Wed May 27 01:42:58 2015 polydo_s
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
  virtual void  setTexture(const gdl::Texture &old);

private:
  gdl::Texture  _texture;
  gdl::Geometry _geometry;

public:
  virtual const std::string	toString();
};

#endif
