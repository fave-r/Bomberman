//
// Box.hh for Box.hh in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 15 21:48:39 2015 clément jean
// Last update Wed May 27 01:42:59 2015 polydo_s
//

#ifndef __BOX_HH__
# define __BOX_HH__

#include <iostream>
#include <Texture.hh>
#include <Geometry.hh>
#include "AObject.hh"
#include "IUpdatable.hh"

class   Box : public AObject, public IUpdatable
{
public:
  Box(float, float);
  ~Box();

public:
  virtual void	draw(gdl::AShader &shader);
  virtual void	update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &);
  virtual bool	initialize();
  virtual void  setTexture(const gdl::Texture &old);

private:
  gdl::Texture  _texture;
  gdl::Geometry _geometry;

public:
  virtual const std::string	toString();
};

#endif
