//
// Bomb.hh for Bomb.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 02:18:58 2015 clément jean
// Last update Thu Jun 11 15:25:02 2015 Leo Thevenet
//

#ifndef __BOMB_HH__
# define __BOMB_HH__

#include <iostream>
#include <Texture.hh>
#include <Model.hh>
#include <unistd.h>

#include "IDestroyable.hh"
#include "IUpdatable.hh"
#include "Fire.hh"
#include "APlayer.hh"
#include "AObject.hh"

class APlayer;

class Bomb : public AObject, public IUpdatable, public IDestroyable
{

private:
  gdl::Model   	_model;
  double	_elapsed;
  float		_livespan;
  APlayer	*_player;
  int		_power;

public:
  Bomb(float x, float y, APlayer *player, const gdl::Clock &clock, int power);
  ~Bomb();

public:
  bool				damage(std::vector<std::vector<AObject *> > &map, int x, int y);
  void				destroy(std::vector<std::vector<AObject *> > &map, APlayer *);

public:
  virtual void			update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map);
  virtual void			draw(gdl::AShader &shader);

public:
  void				setModel(const gdl::Geometry &);
};

#endif
