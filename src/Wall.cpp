//
// Wall.cpp for Wall.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:40:10 2015 clément jean
// Last update Fri May 15 21:45:44 2015 clément jean
//

#include "Wall.hh"

Wall::Wall(float x, float y) : AElement(x, y)
{
}

Wall::~Wall()
{
}

void	Wall::draw() const
{
}

void	Wall::update()
{
}

const std::string	Wall::ToString() const
{
  return "W";
}
