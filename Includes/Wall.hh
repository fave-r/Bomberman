//
// Wall.hh for Wall.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 17:25:07 2015 clément jean
// Last update Sat Jun 13 04:51:17 2015 clément jean
//

#ifndef __WALL_HH__
# define __WALL_HH__

#include "AObject.hh"

class Wall : public AObject
{

private:
  gdl::Geometry		_geometry;

public:
  Wall(float x, float y);
  void	setModel(const gdl::Geometry &geo);

public:
  virtual void	draw(gdl::AShader &shader);
};

#endif
