//
// PhysicalPlayer.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:59:33 2015 polydo_s
// Last update Sat Jun 13 05:12:51 2015 clément jean
//

#ifndef PHYSICAL_PLAYER_HH
#define PHYSICAL_PLAYER_HH

#include <map>
#include <Input.hh>

#include "APlayer.hh"

class	PhysicalPlayer : public APlayer {

private:
  std::map<int, void(APlayer::*)(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock)>	_actions;
  gdl::Input		_input;
  float			_elapse;
public:
  PhysicalPlayer(float, float, APlayer::eOrientation);

public:
  virtual void	update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map, std::list<APlayer *> &players);
  virtual void  draw(gdl::AShader &shader);
  void		setModel(const gdl::Geometry &);
  void		setTexture(const gdl::Texture &text);
public:
  void		setInput(const gdl::Input &input);

};

#endif
