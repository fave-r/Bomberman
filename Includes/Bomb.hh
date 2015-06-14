//
// Bomb.hh for Bomb.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 02:18:58 2015 clément jean
// Last update Sun Jun 14 16:44:56 2015 polydo_s
//

#ifndef __BOMB_HH__
# define __BOMB_HH__

#include <Model.hh>
#include <unistd.h>

#include "IDestroyable.hh"
#include "IUpdatable.hh"
#include "Fire.hh"
#include "APlayer.hh"

class APlayer;

class Bomb : public AObject, public IUpdatable, public IDestroyable
{

private:
  gdl::Model			_model;
  double			_elapsed;
  float				_livespan;
  APlayer			*_player;
  int				_power;
  std::list<APlayer *>		_players;

public:
  Bomb(float x, float y, APlayer *player, const gdl::Clock &clock, int power);
  ~Bomb();

public:
  bool				damage(std::vector<std::vector<AObject *> > &map, int x, int y);
  void				destroy(std::vector<std::vector<AObject *> > &map, APlayer *player);

public:
  virtual void			update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map,
				       std::list<APlayer *> &players);
  virtual void			draw(gdl::AShader &shader);
  virtual const std::string     getType() const;

public:
  int				getPower() const;

public:
  void				setModel(const gdl::Geometry &);
};

#endif
