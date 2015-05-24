//
// Box.cpp for Box.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:49:34 2015 clément jean
// Last update Sun May 24 14:36:42 2015 polydo_s
//

#include "Box.hh"

Box::Box(float x, float y) : AObject(x, y)
{
}

Box::~Box()
{
}

void	Box::draw() const
{

}

void	Box::update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > map)
{
  (void)clock;
  (void)map;
}

bool	Box::initialize()
{
  return true;
}
