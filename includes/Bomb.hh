//
// Bomb.hh for Bomb.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 02:18:58 2015 clément jean
// Last update Thu Jun  4 23:43:08 2015 polydo_s
//

#ifndef __BOMB_HH__
# define __BOMB_HH__

#include <iostream>
#include <Model.hh>
#include <Texture.hh>
#include "AObject.hh"

class	Bomb : public AObject
{
public:
  Bomb(float x, float y);
  ~Bomb();

public:
  virtual void			draw(gdl::AShader &shader);

private:
  gdl::Model	_model;
};
#endif
