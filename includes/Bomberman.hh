//
// Bomberman.hh for Bomberman.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Sun May 17 22:34:06 2015 clément jean
// Last update Thu Jun  4 22:59:51 2015 polydo_s
//

#ifndef __BOMBERMAN_HH__
# define __BOMBERMAN_HH__

#include <vector>
#include <list>
#include <Game.hh>
#include <SdlContext.hh>
#include <AShader.hh>
#include <BasicShader.hh>
#include <Model.hh>

#include "Map.hh"
#include "Cube.hh"
#include "APlayer.hh"
#include "AObject.hh"
#include "TexturePool.hh"
#include "Model.hpp"
#include "Bomb.hh"
#include "Fire.hh"
#include "Music.hh"

class Bomberman
{
public:
  Bomberman(unsigned int, unsigned int, unsigned int);
  ~Bomberman();

public:
  void	ShowMap();
  void	initialize();
  void	init_player();
  void	init_map();
  bool	init_texture();
  bool	update();
  void	draw();

private:
  std::vector< std::vector<AObject *> >		_map;
  std::vector<AObject*>				_objects;
  gdl::SdlContext			       	_context;
  gdl::Clock					_clock;
  gdl::Input					_input;
  gdl::BasicShader				_shader;
  TexturePool					*_texturePool;
  int						_x;
  int						_y;
  Music						*_SoundPlayer;
};

#endif
