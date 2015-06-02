//
// Model.hpp for Model.hpp in /home/jean_c/Graphic
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Wed May  6 00:18:56 2015 clément jean
// Last update Wed Jun  3 00:18:51 2015 clément jean
//

#ifndef __MODEL_HPP__
# define __MODEL_HPP__

#include <iostream>
#include <Geometry.hh>
#include <Texture.hh>
#include <Model.hh>
#include "AObject.hh"
#include "IUpdatable.hh"

class Model : public AObject, public IUpdatable
{

public:
  Model(float x, float y);
  virtual ~Model();
  virtual bool		initialize();
  virtual void		draw(gdl::AShader &shader);
  virtual void		update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &);
  virtual void          setTexture(const gdl::Texture &old);
  void                  move(const int &x, const int &y, const int &z);

public:
  virtual const std::string	toString();

private:
  float _x;
  float _y;
  float _speed;
  gdl::Texture	_texture;
  gdl::Model	_model;

};

#endif
