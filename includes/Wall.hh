//
// Wall.hh for Wall.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 17:25:07 2015 clément jean
// Last update Sun May 24 14:20:43 2015 polydo_s
//

#ifndef __WALL_HH__
# define __WALL_HH__

#include <iostream>
#include "AObject.hh"

class   Wall : public AObject
{
public:
  Wall(float x, float y);
  ~Wall();

public:
  void	draw(const gdl::AShader &shader) const;
};

#endif
