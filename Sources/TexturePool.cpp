// TexturePool.cpp for TexturePool.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Mon May 25 02:15:39 2015 clément jean
// Last update Thu Jun 11 15:40:41 2015 Leo Thevenet
//

#include "TexturePool.hh"

TexturePool::TexturePool()
{
}

TexturePool::~TexturePool()
{
}

void		TexturePool::init()
{
  if (this->_textureBox.load("./Assets/Map/box.fbm/box.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Box texture");
  if (this->_textureWall.load("./Assets/Map/wall.fbm/Wall.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Wall texture");
  if (this->_textureGround.load("./Assets/Map/ground.fbm/ground.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Ground texture");
  if (this->_textureBomb.load("./Assets/Map/bomb.fbm/Bomb_texture.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Bomb texture");
  if (this->_textureFire.load("./Assets/Map/fire.fbm/XPlosion.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Fire texture");
  if (this->_textureGold.load("./Assets/Map/Bonus.fbm/rocher_or.tga", true) == false)
    throw loading_error("TexturePool : Cannot load Gold texture");
}

const gdl::Texture	&TexturePool::getBox()
{
  return this->_textureBox;
}

const gdl::Texture	&TexturePool::getWall()
{
  return this->_textureWall;
}

const gdl::Texture	&TexturePool::getGround()
{
  return this->_textureGround;
}

const gdl::Texture	&TexturePool::getPlayer()
{
  return this->_texturePlayer;
}

const gdl::Texture	&TexturePool::getBomb()
{
  return this->_textureBomb;
}

const gdl::Texture	&TexturePool::getFire()
{
  return this->_textureFire;
}

const gdl::Texture	&TexturePool::getGold()
{
  return this->_textureGold;
}
