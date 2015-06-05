//
// AObject.hpp for AObject.hpp in /home/jean_c/Graphic
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May  5 19:27:04 2015 clément jean
// Last update Fri Jun  5 02:28:51 2015 clément jean
//

#ifndef __AOBJECT_HPP__
# define __AOBJECT_HPP__

#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <BasicShader.hh>
#include <iostream>
#include <vector>
#include <Texture.hh>
#include <Model.hh>
#include <Geometry.hh>
#include <Input.hh>
#include <string>

class	AObject
{
protected:
  float			_x;
  float			_y;
  float			_w;
  float			_h;
  glm::vec3		_position;
  glm::vec3		_rotation;
  glm::vec3		_scale;
  gdl::Texture		_texture;

public:
  AObject(float x, float y, float width, float height);
  virtual ~AObject();

public:
  virtual void		draw(gdl::AShader &shader) = 0;
  void			scale(const glm::vec3 &scale);
  void			translate(const glm::vec3 &v);
  void			rotate(const glm::vec3 &axis, const float &angle);
  void			resetRotate();

public:
  int			getX() const;
  int			getY() const;
  const glm::mat4	getTransformation();

public:
  void			setTexture(const gdl::Texture &old);
  void			SetPos(const glm::vec3 &v);
  virtual void		setModel(const gdl::Geometry &) = 0;
};

#endif
