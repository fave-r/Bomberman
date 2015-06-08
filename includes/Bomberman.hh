//
// Bomberman.hh for Bomberman.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Sun May 17 22:34:06 2015 clément jean
// Last update Mon Jun  8 18:09:28 2015 Leo Thevenet
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
#include <tuple>

#include "Map.hh"
#include "Cube.hh"
#include "APlayer.hh"
#include "AObject.hh"
#include "TexturePool.hh"
#include "Model.hpp"
#include "Bomb.hh"
#include "Fire.hh"
#include "Music.hh"
#include "ModelPool.hh"

class Bomberman
{
public:
  Bomberman(unsigned int, unsigned int, unsigned int);
  Bomberman(const std::string &);
  ~Bomberman();

public:
  void	ShowMap();
  void	initialize();
  void	init_player();
  void  end_init_player();
  void	init_map();
  bool	init_texture();
  bool	update();
  void	draw();
  void	getMap();
private:
  std::vector< std::vector<AObject *> >		_map;
  std::vector<AObject*>				_objects;
  gdl::SdlContext				_context;
  gdl::Clock					_clock;
  gdl::Input					_input;
  gdl::BasicShader				_shader;
  TexturePool					*_texturePool;
  ModelPool					*_modelPool;
  int						_w;
  int						_h;
  int						_p;
  std::list<APlayer *>				_playerlist;
  Music						*_SoundPlayer;
  std::string					_namedMap;
};

#endif
