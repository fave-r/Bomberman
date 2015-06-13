//
// TexturePool.hh for TexturePool.hh in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Mon May 25 02:13:06 2015 clément jean
// Last update Sat Jun 13 04:50:36 2015 clément jean
//

#ifndef __TEXTUREPOOL_HH__
# define __TEXTUREPOOL_HH__

#include <Geometry.hh>
#include <Texture.hh>

#include "Error.hh"

class	TexturePool
{
public:
  TexturePool();
  ~TexturePool();
  void	init();
  const gdl::Texture      &getBox();
  const gdl::Texture	  &getWall();
  const gdl::Texture      &getGround();
  const gdl::Texture      &getPlayer();
  const gdl::Texture	  &getBomb();
  const gdl::Texture      &getFire();
  const gdl::Texture	  &getGold();

private:
  gdl::Texture  _textureBox;
  gdl::Texture  _textureWall;
  gdl::Texture  _textureGround;
  gdl::Texture  _texturePlayer;
  gdl::Texture  _textureBomb;
  gdl::Texture  _textureFire;
  gdl::Texture  _textureGold;
};

#endif
