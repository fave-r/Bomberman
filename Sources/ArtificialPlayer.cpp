//
// ArtificialPlayer.cpp for Bomberman in /home/polydo_s/rendu/Bomberman
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun Jun 14 03:03:34 2015 polydo_s
// Last update Sun Jun 14 21:29:51 2015 clément jean
//

#include "ArtificialPlayer.hh"

ArtificialPlayer::ArtificialPlayer(float x, float y, APlayer::eOrientation orientation)
  : APlayer(x, y, orientation)
{
  this->_id = 0;
  this->_objX = this->_x;
  this->_objY = this->_y;
}

bool ArtificialPlayer::isDanger(std::vector<std::vector<AObject *> > &map, int x, int y)
{
  for (unsigned int i = y; i > 0; --i)
    if (map[i][x])
      {
	Bomb *bomb = dynamic_cast<Bomb *>(map[i][x]);
	if (bomb && bomb->getPower() >= y - i)
	  return (true);
	break;
      }
  for (unsigned int i = x; i < map[y].size(); ++i)
    if (map[y][i])
      {
	Bomb *bomb = dynamic_cast<Bomb *>(map[y][i]);
	if (bomb && bomb->getPower() >= i - x)
	  return (true);
	break;
      }
  for (unsigned int i = y; i < map.size(); ++i)
    if (map[i][x])
      {
	Bomb *bomb = dynamic_cast<Bomb *>(map[i][x]);
	if (bomb && bomb->getPower() >= i - y)
	  return (true);
	break;
      }
  for (unsigned int i = x; i > 0; --i)
    if (map[y][i])
      {
	Bomb *bomb = dynamic_cast<Bomb *>(map[y][i]);
	if (bomb && bomb->getPower() >= x - i)
	  return (true);
	break;
      }
  return (false);
}

void ArtificialPlayer::update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map, std::list<APlayer *> &players)
{
  (void)players;
  this->_elapse = clock.getElapsed();
  if (this->_x != this->_objX || this->_y != this->_objY)
    {
      if (this->_x + (this->_w + this->_w / 10) < this->_objX)
	this->goRight(map, clock);
      else if (this->_x > this->_objX)
	this->goLeft(map, clock);
      else if (this->_y + (this->_h + this->_h / 10) < this->_objY)
	this->goDown(map, clock);
      else if (this->_y > this->_objY)
	this->goUp(map, clock);
      else
	{
	  this->_objX = this->_x;
	  this->_objY = this->_y;
	  this->wait();
	}
    }
  else if (this->isDanger(map, this->_x, this->_y))
    {
      if (!map[this->_y - 1][this->_x] && !this->isDanger(map, this->_x, this->_y - 1))
	this->_objY -= 0.9;
      else if (!map[this->_y][this->_x + 1] && !this->isDanger(map, this->_x + 1, this->_y))
	this->_objX += 0.9;
      else if (!map[this->_y + 1][this->_x] && !this->isDanger(map, this->_x, this->_y + 1))
	this->_objY += 0.9;
      else if (!map[this->_y][this->_x - 1] && !this->isDanger(map, this->_x - 1, this->_y))
	this->_objX -= 0.9;
    }
  else
    {
      this->_objX = this->_x;
      this->_objY = this->_y;
    }
}

void ArtificialPlayer::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}

void ArtificialPlayer::setTexture(const gdl::Texture &text)
{
  this->_texture = text;
}

const std::string ArtificialPlayer::getType() const
{
  return "a";
}
