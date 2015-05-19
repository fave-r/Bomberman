//
// Box.hh for Box.hh in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:48:39 2015 clément jean
// Last update Tue May 19 23:49:19 2015 polydo_s
//

#ifndef __BOX_HH__
# define __BOX_HH__

#include <iostream>
#include "AElement.hh"

class   Box : public AElement
{
public:
  Box(float, float);
  ~Box();

public:
  void	draw() const;
  void	update();
};

#endif
