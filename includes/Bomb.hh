//
// Bomb.hh for Bomb.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 02:18:58 2015 clément jean
// Last update Wed Jun  3 00:16:09 2015 clément jean
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
  virtual bool			initialize();
  virtual void			setTexture(const gdl::Texture &old);
  virtual void			draw(gdl::AShader &shader);
  virtual const std::string     toString();

private:
  gdl::Texture	_texture;
  gdl::Model	_model;

};
#endif
