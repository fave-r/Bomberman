// TexturePool.cpp for TexturePool.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Mon May 25 02:15:39 2015 clément jean
// Last update Wed May 27 11:22:22 2015 clément jean
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
  if (this->_texturePlayer.load("./Assets/marvin.fbm/Main_texture_diffuse2.tga") == false)
    {
      std::cerr << "Cannot load the player texture" << std::endl;
      return (false);
    }
  if (this->_textureGround.load("./Assets/ground.fbm/ground.tga") == false)
    {
      std::cerr << "Cannot load the ground texture" << std::endl;
      return (false);
    }
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
