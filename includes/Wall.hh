//
// Wall.hh for Wall.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 17:25:07 2015 clément jean
// Last update Thu May 21 17:40:20 2015 Leo Thevenet
//

#ifndef __WALL_HH__
# define __WALL_HH__

#include <iostream>
#include "AElement.hh"

class   Wall : public AElement
{
public:
  Wall(float x, float y);
  ~Wall();

public:
  void	draw() const;
  void	update(std::vector<std::vector<AElement *> >);
};

#endif
