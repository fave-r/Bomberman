//
// APlayer.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/src
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:56:39 2015 polydo_s
// Last update Wed May 27 01:40:55 2015 polydo_s
//

#include "APlayer.hh"

APlayer::APlayer(float x, float y, APlayer::eOrientation orientation)
  : AObject(x, y, 0.9, 0.9), _orientation(orientation)
{
  static unsigned id = 1;
  this->_id = id++;
  this->_speed = 0.03;
}

void			APlayer::draw() const
{
  
}

void			APlayer::move(float x, float y, eOrientation orientation, std::vector<std::vector<AObject *> > &map)
{
  AObject		*object;

  object = map[static_cast<int>(y)][static_cast<int>(x)];
  if (object)
    std::cout << object->toString() << std::endl;
  (void)map;
  this->_orientation = orientation;
  this->_x = x;
  this->_y = y;
}

void			APlayer::goUp(std::vector<std::vector<AObject *> > &map)
{
  this->move(this->_x, this->_y - this->_speed, APlayer::UP, map);
}

void			APlayer::goRight(std::vector<std::vector<AObject *> > &map)
{
  this->move(this->_x + this->_speed, this->_y, APlayer::RIGHT, map);
}

void			APlayer::goDown(std::vector<std::vector<AObject *> > &map)
{
  this->move(this->_x, this->_y + this->_speed, APlayer::DOWN, map);
}

void			APlayer::goLeft(std::vector<std::vector<AObject *> > &map)
{
  this->move(this->_x - this->_speed, this->_y, APlayer::LEFT, map);
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
