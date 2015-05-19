//
// Wall.hh for Wall.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 17:25:07 2015 clément jean
// Last update Tue May 19 22:34:00 2015 polydo_s
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
  const std::string	ToString() const;
};

#endif
