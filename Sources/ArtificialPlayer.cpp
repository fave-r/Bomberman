//
// ArtificialPlayer.cpp for Bomberman in /home/polydo_s/rendu/Bomberman
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun Jun 14 03:03:34 2015 polydo_s
// Last update Sun Jun 14 16:58:53 2015 polydo_s
//

#include "ArtificialPlayer.hh"

ArtificialPlayer::ArtificialPlayer(float x, float y, APlayer::eOrientation orientation)
  : APlayer(x, y, orientation)
{

}

bool ArtificialPlayer::isDanger(std::vector<std::vector<AObject *> > &map)
{
  for (unsigned int i = this->_y; i > 0; --i)
    if (map[i][this->_x])
      {
	Bomb *bomb = dynamic_cast<Bomb *>(map[this->_y][this->_x]);
	if (bomb && bomb->getPower() >= this->_y - i)
	  return (true);
	break;
      }
  for (unsigned int i = this->_x; i < map[this->_y].size(); ++i)
    if (map[this->_y][i])
      {
	Bomb *bomb = dynamic_cast<Bomb *>(map[this->_y][i]);
	if (bomb && bomb->getPower() >= i - this->_x)
	  return (true);
	break;
      }
  for (unsigned int i = this->_y; i < map.size(); ++i)
    if (map[i][this->_x])
      {
	Bomb *bomb = dynamic_cast<Bomb *>(map[i][this->_x]);
	if (bomb && bomb->getPower() >= i - this->_y)
	  return (true);
	break;
      }
  for (unsigned int i = this->_x; i > 0; --i)
    if (map[this->_y][i])
      {
	Bomb *bomb = dynamic_cast<Bomb *>(map[this->_y][i]);
	if (bomb && bomb->getPower() >= this->_x - i)
	  return (true);
	break;
      }
  return (false);
}

void ArtificialPlayer::update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map, std::list<APlayer *> &players)
{
  (void)players;
  this->_elapse = clock.getElapsed();
  if (this->isDanger(map))
    this->putBomb(map, clock);
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
