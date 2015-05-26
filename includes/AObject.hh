//
// AObject.hpp for AObject.hpp in /home/jean_c/Graphic
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May  5 19:27:04 2015 clément jean
// Last update Tue May 26 02:16:20 2015 clément jean
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

class AObject
{
public:
  AObject(float x, float y);
  virtual ~AObject();
  virtual void		draw(gdl::AShader &shader) = 0;
  virtual bool          initialize() = 0;
  virtual void          setTexture(const gdl::Texture &old) = 0;
  void			translate(const glm::vec3 &v);
  void			SetPos(const glm::vec3 &v);
  void			rotate(const glm::vec3 &axis, const float &angle);
  void			scale(const glm::vec3 &scale);
  const glm::mat4	getTransformation();

protected:
  float			_x;
  float			_y;
  glm::vec3		_position;
  glm::vec3		_rotation;
  glm::vec3		_scale;
  gdl::Input		_input;
};

#endif
