//
// Wall.cpp for Wall.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:40:10 2015 clément jean
// Last update Sun May 24 14:25:07 2015 polydo_s
//

#include "Wall.hh"

Wall::Wall(float x, float y) : AObject(x, y)
{
}

Wall::~Wall()
{
}

void	Wall::draw(const gdl::AShader &shader) const
{
  (void)shader;
}
