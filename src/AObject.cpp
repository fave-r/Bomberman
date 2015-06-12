//
// AObject.cpp for AObject.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 19:27:19 2015 clément jean
// Last update Fri Jun 12 01:07:15 2015 clément jean
//

#include "AObject.hh"

Music *AObject::_SoundPlayer = NULL;

AObject::AObject(float x, float y, float w, float h)
  : _x(x), _y(y), _w(w), _h(h), _position(0, 0, 0), _rotation(0, 0, 0), _scale(1, 1, 1)
{
  if (_SoundPlayer == NULL)
    {
      this->_SoundPlayer = new Music();
      this->_SoundPlayer->createSound("./Assets/Sounds/Fuse.mp3", "bombstart");
      this->_SoundPlayer->createSound("./Assets/Sounds/ExplosionSound.wav", "explosion");
      this->_SoundPlayer->createSound("./Assets/Sounds/DeathSound.mp3", "Death");
    }
}

AObject::~AObject()
{
}

void			AObject::scale(const glm::vec3 &scale)
{
  this->_scale *= scale;
}

void			AObject::translate(const glm::vec3 &v)
{
  this->_position += v;
}

void			AObject::rotate(const glm::vec3 &axis, const float &angle)
{
  this->_rotation += axis * angle;
}

void			AObject::resetRotate()
{
  this->_rotation = glm::vec3(0, 0, 0);
}

bool			AObject::isColliding(AObject *other) const
{
  if (this->_x < other->getX() + other->getWidth() &&
      this->_x + this->_w > other->getX() &&
      this->_y < other->getY() + other->getHeight() &&
      this->_y + this->_h > other->getHeight())
    return true;
  return false;
}

float			AObject::getX() const
{
  return this->_x;
}

float			AObject::getY() const
{
  return this->_y;
}

float			AObject::getWidth() const
{
  return this->_w;
}

float			AObject::getHeight() const
{
  return this->_h;
}

const glm::mat4		AObject::getTransformation()
{
  glm::mat4		transform(1);

  transform = glm::translate(transform, this->_position);
  transform = glm::rotate(transform, this->_rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, this->_rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, this->_rotation.z, glm::vec3(0, 0, 1));
  transform = glm::scale(transform, this->_scale);
  return (transform);
}

void			AObject::SetPos(const glm::vec3 &v)
{
  this->_position.x = v.x;
  this->_position.y = v.y;
  this->_position.z = v.z;
}

void                  AObject::setTexture(const gdl::Texture &old)
{
  this->_texture = old;
}
