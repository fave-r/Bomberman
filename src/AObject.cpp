//
// AObject.cpp for AObject.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 19:27:19 2015 clément jean
// Last update Tue May 19 19:47:45 2015 clément jean
//

#include "AObject.hh"

AObject::AObject() : this->_position(0, 0, 0),
		     this->_rotation(0, 0, 0),
		     this->_scale(1, 1, 1)
{
}

AObject::~AObject()
{
}

void			AObject::translate(const glm::vec3 &v)
{
  this->_position += v;
}

void			AObject::SetPos(const glm::vec3 &v)
{
  this->_position.x = v.x;
  this->_position.y = v.y;
  this->_position.z = v.z;
}

void			AObject::rotate(const glm::vec3 &axis, const float &angle)
{
  this->_rotation += axis * angle;
}

void			AObject::scale(const glm::vec3 &scale)
{
  this->_scale *= scale;
}

const glm::mat4		&AObject::getTransformation()
{
  glm::mat4		transform(1);

  transform = glm::rotate(transform, this->_rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, this->_rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, this->_rotation.z, glm::vec3(0, 0, 1));
  transform = glm::translate(transform, this->_position);
  transform = glm::scale(transform, this->_scale);
  return (transform);
}
