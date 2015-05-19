//
// Wall.cpp for Wall.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:40:10 2015 clément jean
// Last update Tue May 19 22:34:51 2015 polydo_s
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

void	Wall::update(std::vector<std::vector<AElement *> >)
{
}

const std::string	Wall::ToString() const
{
  return "W";
}
