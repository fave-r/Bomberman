//
// ArtificialPlayer.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 20:05:43 2015 polydo_s
// Last update Sun Jun 14 17:58:50 2015 polydo_s
//

#ifndef ARTIFICIAL_PLAYER_HH
#define ARTIFICIAL_PLAYER_HH

#include "APlayer.hh"
#include "Bomb.hh"

class	ArtificialPlayer : public APlayer {

public:
  ArtificialPlayer(float x, float y, APlayer::eOrientation orientation);

private:
  bool isDanger(std::vector<std::vector<AObject *> > &map, int x, int y);

public:
  virtual void update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map, std::list<APlayer *> &players);
  void setModel(const gdl::Geometry &);
  void setTexture(const gdl::Texture &text);

public:
  virtual const std::string getType() const;
};

#endif
