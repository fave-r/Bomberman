//
// PhysicalPlayer.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/src
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Fri May 15 16:55:48 2015 polydo_s
// Last update Tue May 26 23:34:52 2015 polydo_s
//

#include "PhysicalPlayer.hh"

PhysicalPlayer::PhysicalPlayer(float x, float y, APlayer::eOrientation orientation)
  : APlayer(x, y, orientation)
{
  this->_x = x;
  this->_y = y;
  if (this->_id == 1)
    {
      this->_actions[SDLK_UP] = &APlayer::goUp;
      this->_actions[SDLK_RIGHT] = &APlayer::goRight;
      this->_actions[SDLK_DOWN] = &APlayer::goDown;
      this->_actions[SDLK_LEFT] = &APlayer::goLeft;
    }
}

void	PhysicalPlayer::update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map)
{
  (void)clock;
  std::map<int, void(APlayer::*)(std::vector<std::vector<AObject *> > &)>::const_iterator it;

  for (it = this->_actions.begin(); it != this->_actions.end(); ++it)
    {
      if (this->_input.getKey(it->first))
	(this->*(*it).second)(map);
    }
}

void	PhysicalPlayer::setInput(const gdl::Input &input)
{
  this->_input = input;
}

void	PhysicalPlayer::draw(gdl::AShader &shader)
{
  (void)shader;
}

bool	PhysicalPlayer::initialize()
{
  return true;
}

void	PhysicalPlayer::setTexture(const gdl::Texture &old)
{
  (void)old;
}

