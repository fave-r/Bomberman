//
// Model.hpp for Model.hpp in /home/jean_c/Graphic
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Wed May  6 00:18:56 2015 clément jean
// Last update Tue May 19 21:55:38 2015 clément jean
//

#ifndef __MODEL_HPP__
# define __MODEL_HPP__

#include <iostream>
#include <Geometry.hh>
#include <Texture.hh>
#include <Model.hh>
#include "AObject.hh"

class Model : public AObject
{
public:
  Model();
  virtual ~Model();
  virtual bool		initialize();
  virtual void          update(const gdl::Clock &clock);
  virtual void		draw(gdl::AShader &shader);

private:
  gdl::Texture	_texture;
  gdl::Model	_model;
  float		_speed;
};

#endif
