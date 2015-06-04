//
// APlayer.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:56:12 2015 polydo_s
// Last update Wed Jun  3 19:36:53 2015 polydo_s
//

#ifndef PLAYER_HH
#define PLAYER_HH

#include <iostream>

#include "AObject.hh"
#include "Bomb.hh"
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
  float		_delta;
  float		_speed;
  bool		_inAnim;
  gdl::Texture	_texture;
  gdl::Model	_model;

public:
  APlayer(float, float, APlayer::eOrientation);

public:
  virtual void		draw(gdl::AShader &shader);
  virtual void		update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &) = 0;

public:
  void			putBomb(std::vector<std::vector<AObject *> >&map, const gdl::Clock &clock);
  void			goUp(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock);
  void			goRight(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock);
  void			goDown(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock);
  void			goLeft(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock);
  void                  move(const int &x, const int &y, const int &z);

public:
  unsigned int		getId() const;
  eOrientation		getOrientation() const;
  float			getY();
  float			getX();

public:
  virtual void		setTexture(const gdl::Texture &old);

public:
  const std::string	toString();
};

#endif
