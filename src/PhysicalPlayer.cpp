//
// PhysicalPlayer.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/src
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Fri May 15 16:55:48 2015 polydo_s
// Last update Sun May 17 22:55:29 2015 polydo_s
//

#include "PhysicalPlayer.hh"

PhysicalPlayer::PhysicalPlayer(float x, float y, ACharacter::eOrientation orientation)
  : APlayer(x, y, orientation)
{
  if (this->_id == 1)
    {
      
    }
  else
    {

    }
}

void	PhysicalPlayer::update()
{
  if (this->_input.getKey(SDLK_UP))
    {
    }
  else if (this->_input.getKey(SDLK_DOWN))
    {
    }
  else if (this->_input.getKey(SDLK_LEFT))
    {
    }
  else if (this->_input.getKey(SDLK_RIGHT))
    {
    }
}
