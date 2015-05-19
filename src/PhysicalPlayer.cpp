//
// PhysicalPlayer.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/src
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Fri May 15 16:55:48 2015 polydo_s
// Last update Wed May 20 00:28:00 2015 polydo_s
//

#include "PhysicalPlayer.hh"

PhysicalPlayer::PhysicalPlayer(float x, float y, ACharacter::eOrientation orientation, gdl::SdlContext *context)
  : APlayer(x, y, orientation), _context(context)
{
  
  if (this->_id == 1)
    {
      this->_actions[SDLK_UP] = &ACharacter::goUp;
      this->_actions[SDLK_RIGHT] = &ACharacter::goRight;
      this->_actions[SDLK_DOWN] = &ACharacter::goDown;
      this->_actions[SDLK_LEFT] = &ACharacter::goLeft;
    }
}

void	PhysicalPlayer::update(std::vector<std::vector<AElement *> >)
{
  std::map<int, void(ACharacter::*)(void)>::const_iterator it;

  for (it = this->_actions.begin(); it != this->_actions.end(); ++it)
    {
      if (this->_input.getKey(SDLK_UP))
	std::cout << "UP" << std::endl;
    }
}
