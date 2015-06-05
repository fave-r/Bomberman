//
// Bomb.hh for Bomb.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 02:18:58 2015 clément jean
// Last update Fri Jun  5 02:36:53 2015 clément jean
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
  void				setModel(const gdl::Geometry &);
private:
  gdl::Model	_model;
};
#endif
