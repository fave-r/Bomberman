//
// APlayer.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/src
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:56:39 2015 polydo_s
// Last update Fri May 29 22:53:21 2015 clément jean
//

#include "APlayer.hh"

APlayer::APlayer(float x, float y, APlayer::eOrientation orientation)
  : AObject(x, y, 0.85, 0.85), _orientation(orientation)
{
  static unsigned id = 1;
  this->_id = id++;
  this->_speed = 0.05;
}

void			APlayer::draw() const
{
}

void			APlayer::goUp(std::vector<std::vector<AObject *> > &map)
{
  AObject		*object;
  ICrossable		*crossable;

  object = map[static_cast<int>(this->_y - this->_speed)][static_cast<int>(this->_x)];
  crossable = dynamic_cast<ICrossable *>(object);
  if (!object || crossable)
    {
      this->_y -= this->_speed;
    }
  this->_orientation = APlayer::UP;
}

void			APlayer::goRight(std::vector<std::vector<AObject *> > &map)
{
  AObject		*object;
  ICrossable		*crossable;

  object = map[static_cast<int>(this->_y + this->_h)][static_cast<int>(this->_x + this->_w + this->_speed)];
  crossable = dynamic_cast<ICrossable *>(object);
  if (!object || crossable)
    {
      this->_x += this->_speed;
    }
  this->_orientation = APlayer::RIGHT;
}

void			APlayer::goDown(std::vector<std::vector<AObject *> > &map)
{
  AObject		*object;
  ICrossable		*crossable;

  object = map[static_cast<int>(this->_y + this->_h + this->_speed)][static_cast<int>(this->_x + this->_w)];
  crossable = dynamic_cast<ICrossable *>(object);
  if (!object || crossable)
    {
      this->_y += this->_speed;
    }
  this->_orientation = APlayer::DOWN;
}

void			APlayer::goLeft(std::vector<std::vector<AObject *> > &map)
{
  AObject		*object;
  ICrossable		*crossable;

  object = map[static_cast<int>(this->_y)][static_cast<int>(this->_x - this->_speed)];
  crossable = dynamic_cast<ICrossable *>(object);
  if (!object || crossable)
    {
      this->_x -= this->_speed;
    }
  this->_orientation = APlayer::LEFT;
}

unsigned int		APlayer::getId() const
{
  return this->_id;
}

float			APlayer::getX()
{
  return this->_x;
}

float			APlayer::getY()
{
  return this->_y;
}

const std::string	APlayer::toString()
{
  return "P";
}

APlayer::eOrientation		APlayer::getOrientation() const
{
  return this->_orientation;
}
