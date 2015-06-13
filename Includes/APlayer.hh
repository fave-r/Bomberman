//
// APlayer.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:56:12 2015 polydo_s
// Last update Sat Jun 13 04:41:16 2015 clément jean
//

#ifndef PLAYER_HH
# define PLAYER_HH

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
  unsigned int		_id;
  bool			_dead;
  eOrientation		_orientation;
  float			_delta;
  float			_speed;
  int			_power;
  int			_currentBombs;
  int			_maxBombs;
  bool			_inAnim;
  gdl::Texture		_texture;
  gdl::Model		_model;
  int			_score;
  std::list<APlayer *>	_playerList;

public:
  APlayer(float, float, APlayer::eOrientation);
  virtual ~APlayer();

public:
  virtual void		draw(gdl::AShader &shader);
  virtual void		update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map, std::list<APlayer *> &players) = 0;

public:
  void			wait();
  void			updateScore(int);

public:
  void			putBomb(std::vector<std::vector<AObject *> >&map, const gdl::Clock &clock);
  void			goUp(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock);
  void			goRight(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock);
  void			goDown(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock);
  void			goLeft(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock);
  void                  move(const int &x, const int &y, const int &z);

public:
  bool			isDead() const;
  eOrientation		getOrientation() const;

public:
  void			kill();
  void			decreaseCurrentBombs();
  void			increaseSpeed();
  void			increasePower();
  void			increaseMaxBombs();
};

#endif
