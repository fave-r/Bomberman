//
// Cube.hpp for Cube.hpp in /home/jean_c/Graphic
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May  5 19:29:04 2015 clément jean
// Last update Tue May 19 20:49:28 2015 clément jean
//

#ifndef __CUBE_HPP__
# define __CUBE_HPP__

#include <iostream>
#include <Geometry.hh>
#include <Texture.hh>
#include "AObject.hh"

class Cube : public AObject
{
public:
  Cube();
  virtual ~Cube();
  const gdl::Texture	&getTexture() const;
  const gdl::Geometry	&getGeometry() const;
  void			setGeometry(const gdl::Geometry &old);
  void			setTexture(const gdl::Texture &old);
  const bool		&newTexture();
  virtual bool		initialize();
  void			move(const int &x, const int &y, const int &z);
  virtual void		update(const gdl::Clock &clock);
  virtual void		draw(const gdl::AShader &shader);

private:
  gdl::Geometry _geometry;
  float		_speed;
  gdl::Texture	_texture;
};

#endif
