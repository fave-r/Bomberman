//
// Player.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun May  3 21:28:46 2015 polydo_s
// Last update Mon May  4 00:19:45 2015 polydo_s
//

#include "Player.hh"

Player::Player(bool bot)
  : _bot(bot)
{
}

unsigned int	Player::getId() const
{
  return this->_id;
}

bool		Player::isBot() const
{
  return this->_bot;
}
