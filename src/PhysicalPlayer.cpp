//
// PhysicalPlayer.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/src
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Fri May 15 16:55:48 2015 polydo_s
// Last update Wed Jun  3 19:11:02 2015 polydo_s
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
      this->_actions[SDLK_SPACE] = &APlayer::putBomb;
    }
  else
    {
      this->_actions[SDLK_z] = &APlayer::goUp;
      this->_actions[SDLK_d] = &APlayer::goRight;
      this->_actions[SDLK_s] = &APlayer::goDown;
      this->_actions[SDLK_q] = &APlayer::goLeft;
      this->_actions[SDLK_0] = &APlayer::putBomb;
    }
}

void	PhysicalPlayer::update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map)
{
  bool	inMap = false;
  std::map<int, void(APlayer::*)(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock)>::const_iterator it;

  for (it = this->_actions.begin(); it != this->_actions.end(); ++it)
    {
      if (this->_input.getKey(it->first))
	{
	  inMap = true;
	  (this->*(*it).second)(map, clock);
	  break;
	}
    }
  if (!inMap)
    {
      this->_inAnim = false;
      this->_model.setCurrentSubAnim("wait");
    }
}

void	PhysicalPlayer::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), 0.03);
}

bool	PhysicalPlayer::initialize()
{
  ///NE SERT A RIEN
  return true;
}

void	PhysicalPlayer::setInput(const gdl::Input &input)
{
  this->_input = input;
}
