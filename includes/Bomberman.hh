//
// Bomberman.hh for Bomberman.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Sun May 17 22:34:06 2015 clément jean
// Last update Tue May 19 23:58:00 2015 polydo_s
//

#ifndef __BOMBERMAN_HH__
# define __BOMBERMAN_HH__

#include <vector>
#include <list>
#include <Game.hh>
#include <SdlContext.hh>
#include <AShader.hh>
#include <BasicShader.hh>

#include "Cube.hh"
#include "APlayer.hh"
#include "AElement.hh"
#include "MapGenerator.hh"

class	Bomberman : public gdl::Game
{
public:
  Bomberman(const unsigned int &, const unsigned int &);
  ~Bomberman();

public:
  void	ShowMap();
  bool	initialize();
  bool	update();
  void	draw();

private:
  std::vector< std::vector<AElement *> >	_map;
  std::list<APlayer *>			       	_playerlist;
  gdl::SdlContext			       	_context;
  gdl::Clock					_clock;
  gdl::Input					_input;
  gdl::BasicShader				_shader;
  std::vector<AObject*>				_objects;
  int						_x;
  int						_y;
};

#endif
