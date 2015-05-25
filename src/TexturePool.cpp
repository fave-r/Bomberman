// TexturePool.cpp for TexturePool.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Mon May 25 02:15:39 2015 clément jean
// Last update Mon May 25 13:46:45 2015 clément jean
//

#include "TexturePool.hh"

TexturePool::TexturePool()
{
}

TexturePool::~TexturePool()
{
}

bool		TexturePool::init()
{
  if (this->_textureBox.load("./Assets/box.fbm/box.tga") == false)
    {
      std::cerr << "Cannot load the box texture" << std::endl;
      return (false);
    }
  if (this->_textureWall.load("./Assets/wall.fbm/Wall.tga") == false)
    {
      std::cerr << "Cannot load the wall texture" << std::endl;
      return (false);
    }
  //if ()
  return true;
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

