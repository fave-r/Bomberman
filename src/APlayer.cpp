//
// APlayer.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/src
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:56:39 2015 polydo_s
// Last update Fri May 29 18:22:40 2015 polydo_s
//

#include "APlayer.hh"

APlayer::APlayer(float x, float y, APlayer::eOrientation orientation)
  : AObject(x, y, 0.85, 0.85), _orientation(orientation), _delta(0.05), _speed(2)
{
  static unsigned id = 1;
  this->_id = id++;
}

void			APlayer::draw() const
{
  
}

void			APlayer::goUp(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock)
{
  AObject		*dest;
  ICrossable		*crossable;

  dest = map[static_cast<int>(this->_y - this->_delta)][static_cast<int>(this->_x)];
  crossable = dynamic_cast<ICrossable *>(dest);
  if (!dest || crossable)
    {
      this->_y -= static_cast<float>(clock.getElapsed() * this->_speed);
    }
  this->_orientation = APlayer::UP;
}

void			APlayer::goRight(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock)
{
  AObject		*dest;
  ICrossable		*crossable;

  dest = map[static_cast<int>(this->_y + this->_h)][static_cast<int>(this->_x + this->_w + this->_delta)];
  crossable = dynamic_cast<ICrossable *>(dest);
  if (!dest || crossable)
    {
      this->_x += static_cast<float>(clock.getElapsed() * this->_speed);
    }
  this->_orientation = APlayer::RIGHT;
}

void			APlayer::goDown(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock)
{
  AObject		*dest;
  ICrossable		*crossable;

  dest = map[static_cast<int>(this->_y + this->_h + this->_delta)][static_cast<int>(this->_x + this->_w)];
  crossable = dynamic_cast<ICrossable *>(dest);
  if (!dest || crossable)
    {
      this->_y += static_cast<float>(clock.getElapsed() * this->_speed);
    }
  this->_orientation = APlayer::DOWN;
}

void			APlayer::goLeft(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock)
{
  AObject		*dest;
  ICrossable		*crossable;

  dest = map[static_cast<int>(this->_y)][static_cast<int>(this->_x - this->_delta)];
  crossable = dynamic_cast<ICrossable *>(dest);
  if (!dest || crossable)
    {
      this->_x -= static_cast<float>(clock.getElapsed() * this->_speed);
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
