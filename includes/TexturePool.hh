//
// TexturePool.hh for TexturePool.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Mon May 25 02:13:06 2015 clément jean
// Last update Mon May 25 02:21:43 2015 clément jean
//

#ifndef __TEXTUREPOOL_HH__
# define __TEXTUREPOOL_HH__

#include <Geometry.hh>
#include <Texture.hh>
#include <iostream>

class	TexturePool
{
public:
  TexturePool();
  ~TexturePool();
  bool	init();
  const gdl::Texture      &getBox();
  const gdl::Texture      &getWall();
  const gdl::Texture      &getGround();
  const gdl::Texture      &getPlayer();

private:
  gdl::Texture  _textureBox;
  gdl::Texture  _textureWall;
  gdl::Texture  _textureGround;
  gdl::Texture  _texturePlayer;
};

#endif
