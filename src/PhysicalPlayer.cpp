//
// PhysicalPlayer.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/src
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Fri May 15 16:55:48 2015 polydo_s
// Last update Thu May 21 11:01:20 2015 polydo_s
//

#include "PhysicalPlayer.hh"

PhysicalPlayer::PhysicalPlayer(float x, float y, APlayer::eOrientation orientation)
  : APlayer(x, y, orientation)
{
  
  if (this->_id == 1)
    {
      this->_actions[SDLK_UP] = &APlayer::goUp;
      this->_actions[SDLK_RIGHT] = &APlayer::goRight;
      this->_actions[SDLK_DOWN] = &APlayer::goDown;
      this->_actions[SDLK_LEFT] = &APlayer::goLeft;
    }
}

void	PhysicalPlayer::update(std::vector<std::vector<AElement *> >)
{
  std::map<int, void(APlayer::*)(void)>::const_iterator it;

  for (it = this->_actions.begin(); it != this->_actions.end(); ++it)
    {
      if (this->_input.getKey(SDLK_UP))
  	std::cout << "UP" << std::endl;
    }
}

void	PhysicalPlayer::setInput(const gdl::Input &input)
{
  this->_input = input;
}
