//
// Ground.hh for Ground.hh in /home/jean_c/Bomberman/Includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri Jun 12 22:44:42 2015 clément jean
// Last update Fri Jun 12 22:47:27 2015 clément jean
//

#ifndef __GROUND_HPP__
# define __GROUND_HPP__

#include <iostream>
#include <Geometry.hh>
#include <Texture.hh>
#include "AObject.hh"

class Ground : public AObject
{

private:
  gdl::Geometry _geometry;

public:
  Ground(float x, float y);

public:
  const gdl::Texture	&getTexture() const;
  const gdl::Geometry	&getGeometry() const;
  void			setGeometry(const gdl::Geometry &old);
  void			move(const int &x, const int &y, const int &z);
  void			setModel(const gdl::Geometry &);
public:
  virtual void		draw(gdl::AShader &shader);
};

#endif
