//
// Bomb.hh for Bomb.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 02:18:58 2015 clément jean
// Last update Sun Jun  7 02:14:58 2015 polydo_s
//

#ifndef __BOMB_HH__
# define __BOMB_HH__

#include <iostream>
#include <Texture.hh>
#include <Model.hh>

#include "AObject.hh"
#include "APlayer.hh"
#include "Fire.hh"
#include "IUpdatable.hh"
#include "IDestroyable.hh"

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
  void				destroy(std::vector<std::vector<AObject *> > &map);

public:
  virtual void			update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map);
  virtual void			draw(gdl::AShader &shader);

public:
  bool				isExploding() const;

public:
  void				setModel(const gdl::Geometry &);
};

#endif
