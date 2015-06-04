//
// Cube.hpp for Cube.hpp in /home/jean_c/Graphic
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May  5 19:29:04 2015 clément jean
// Last update Fri Jun  5 00:00:29 2015 polydo_s
//

#ifndef __CUBE_HPP__
# define __CUBE_HPP__

#include <iostream>
#include <Geometry.hh>
#include <Texture.hh>
#include "AObject.hh"
#include "IUpdatable.hh"

class Cube : public AObject
{

private:
  gdl::Geometry _geometry;

public:
  Cube(float x, float y);
  ~Cube();

public:
  const gdl::Texture	&getTexture() const;
  const gdl::Geometry	&getGeometry() const;
  void			setGeometry(const gdl::Geometry &old);
  void			move(const int &x, const int &y, const int &z);

public:
  virtual void		draw(gdl::AShader &shader);
};

#endif
