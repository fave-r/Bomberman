//
// PhysicalPlayer.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/src
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Fri May 15 16:55:48 2015 polydo_s
// Last update Sat May 16 00:07:41 2015 clément jean
//

#include "PhysicalPlayer.hh"

PhysicalPlayer::PhysicalPlayer(float x, float y, ACharacter::eOrientation orientation)
  : APlayer(x, y, orientation)
{

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
