//
// Box.hh for Box.hh in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:48:39 2015 clément jean
// Last update Fri May 15 21:49:05 2015 clément jean
//

#ifndef __BOX_HH__
# define __BOX_HH__

#include <iostream>
#include "AElement.hh"

class   Box : public AElement
{
public:
  Box(float x, float y);
  ~Box();

public:
  void	draw() const;
  void	update();
  const std::string	ToString() const;
};

#endif
