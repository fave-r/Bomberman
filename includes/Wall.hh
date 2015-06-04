//
// Wall.hh for Wall.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 17:25:07 2015 clément jean
// Last update Fri Jun  5 00:06:46 2015 polydo_s
//

#ifndef __WALL_HH__
# define __WALL_HH__

#include <iostream>
#include <Texture.hh>
#include <Geometry.hh>
#include "AObject.hh"

class   Wall : public AObject
{

private:
  gdl::Geometry		_geometry;

public:
  Wall(float x, float y);

public:
  virtual void	draw(gdl::AShader &shader);
};

#endif
