//
// PhysicalPlayer.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/src
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Fri May 15 16:55:48 2015 polydo_s
// Last update Sun Jun 14 16:11:15 2015 polydo_s
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
      this->_actions[SDLK_SPACE] = &APlayer::putBomb;
      this->_actions[4] = &APlayer::goUp;
      this->_actions[5] = &APlayer::goRight;
      this->_actions[6] = &APlayer::goDown;
      this->_actions[7] = &APlayer::goLeft;
      this->_actions[14] = &APlayer::putBomb;
    }
  else
    {
      this->_actions[SDLK_z] = &APlayer::goUp;
      this->_actions[SDLK_d] = &APlayer::goRight;
      this->_actions[SDLK_s] = &APlayer::goDown;
      this->_actions[SDLK_q] = &APlayer::goLeft;
      this->_actions[SDLK_e] = &APlayer::putBomb;
      this->_actions[4] = &APlayer::goUp;
      this->_actions[5] = &APlayer::goRight;
      this->_actions[6] = &APlayer::goDown;
      this->_actions[7] = &APlayer::goLeft;
      this->_actions[14] = &APlayer::putBomb;
    }
}

void			PhysicalPlayer::update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map
					       , std::list<APlayer *> &players)
{
  (void)players;
  bool validKey = false;
  std::map<int, void(APlayer::*)(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock)>::const_iterator it;

  SDL_Joystick *aa = SDL_JoystickOpen(this->_id - 1);

  this->_elapse = clock.getElapsed();
  for (it = this->_actions.begin(); it != this->_actions.end(); ++it)
    {
      if (this->_input.getKey(it->first) || SDL_JoystickGetButton(aa, it->first) == 1)
	{
	  validKey = true;
	  (this->*(*it).second)(map, clock);
	}
    }
  if (!validKey)
    this->wait();
}

void			PhysicalPlayer::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), this->_elapse / 3 * this->_speed);
}

void	PhysicalPlayer::setInput(const gdl::Input &input)
{
  this->_input = input;
}

void			PhysicalPlayer::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}

void			PhysicalPlayer::setTexture(const gdl::Texture &text)
{
  this->_texture = text;
}

const std::string	PhysicalPlayer::getType() const
{
  return("P");
}
