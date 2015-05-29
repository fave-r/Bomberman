//
// APlayer.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:56:12 2015 polydo_s
// Last update Fri May 29 00:41:23 2015 polydo_s
//

#ifndef PLAYER_HH
#define PLAYER_HH

#include <iostream>

#include "AObject.hh"
#include "ICrossable.hh"
#include "IUpdatable.hh"

class	APlayer : public AObject, public IUpdatable {

public:
  enum eOrientation {
    UP,
    RIGHT,
    DOWN,
    LEFT
  };

protected:
  unsigned int	_id;
  eOrientation	_orientation;
  float		_speed;

public:
  APlayer(float, float, APlayer::eOrientation);

public:
  virtual void		draw() const;
  virtual void		update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &) = 0;

protected:
  void			move(float, float, eOrientation, std::vector<std::vector<AObject *> > &);

public:
  void			goUp(std::vector<std::vector<AObject *> > &);
  void			goRight(std::vector<std::vector<AObject *> > &);
  void			goDown(std::vector<std::vector<AObject *> > &);
  void			goLeft(std::vector<std::vector<AObject *> > &);

public:
  unsigned int		getId() const;
  eOrientation		getOrientation() const;
  float			getY();
  float			getX();

public:
  const std::string	toString();
};

#endif
