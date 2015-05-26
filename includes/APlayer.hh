//
// APlayer.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:56:12 2015 polydo_s
// Last update Tue May 26 02:27:53 2015 clément jean
//

#ifndef PLAYER_HH
#define PLAYER_HH

#include <iostream>

#include "AObject.hh"
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
  float		_x;
  float		_y;

public:
  APlayer(float, float, APlayer::eOrientation);

public:
  virtual void	draw() const;
  virtual void	update(const gdl::Clock &clock, std::vector<std::vector<AObject *> >) = 0;

protected:
  void			move(eOrientation);

public:
  void			goUp();
  void			goRight();
  void			goDown();
  void			goLeft();

public:
  unsigned int		getId() const;
  eOrientation		getOrientation() const;
  float			getY();
  float			getX();
  void			setY(float y);
  void			setX(float x);

public:
  void	setOrientation(eOrientation);
};

#endif
