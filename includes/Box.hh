//
// Box.hh for Box.hh in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:48:39 2015 clément jean
// Last update Sun May 24 14:39:00 2015 polydo_s
//

#ifndef __BOX_HH__
# define __BOX_HH__

#include <iostream>
#include "AObject.hh"
#include <Texture.hh>

class   Box : public AObject
{
public:
  Box(float, float);
  ~Box();

public:
  void	draw() const;
  void	update(const gdl::Clock &clock, std::vector<std::vector<AObject *> >);
  bool	initialize();

private:
  gdl::Texture  _texture;
};

#endif
