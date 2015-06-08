//
// Bomb.cpp for Bomb.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 02:23:16 2015 clément jean
// Last update Mon Jun  8 16:05:59 2015 clément jean
//

#include <unistd.h>
#include "Bomb.hh"

Bomb::Bomb(float x, float y, APlayer *player, const gdl::Clock &clock, int power)
  : AObject(x, y, 0.9, 0.9), _elapsed(clock.getElapsed()), _livespan(2.5), _player(player), _power(power)
{
  if (this->_model.load("./Assets/Map/bomb.fbx") == false)
    throw std::runtime_error("Cannot load the bomb");
  this->translate(glm::vec3(this->_x, 1, this->_y));
  if (this->_model.createSubAnim(0, "run", 0, 60) == false)
    throw std::runtime_error("Can't load bomb's animation");
  this->scale(glm::vec3(0.7, 0.7, 0.7));
  this->_model.setCurrentSubAnim("run");
  this->_SoundPlayer->playSound("bombstart", false);
}

Bomb::~Bomb() {}

void			Bomb::destroy(std::vector<std::vector<AObject *> > &map)
{
  int	x = this->_x;
  int	y = this->_y;

  map[y][x] = new Fire(x, y);
  for (int i = y - 1, j = this->_power; j >= 0; --i, --j)
    {
      IDestroyable *destroyable = dynamic_cast<IDestroyable *>(map[i][x]);
      if (destroyable)
	{
	  map[i][x] = new Fire(x, i);
	  destroyable->destroy(map);
	  break;
	}
      else if (!map[i][x])
	map[i][x] = new Fire(x, i);
      else if (map[i][x] && !dynamic_cast<ICrossable *>(map[i][x]))
	break;
    }
  for (int i = x + 1, j = this->_power; j >= 0; ++i, --j)
    {
      IDestroyable *destroyable = dynamic_cast<IDestroyable *>(map[y][i]);
      if (destroyable)
  	{
  	  map[y][i] = new Fire(i, y);
  	  destroyable->destroy(map);
	  break;
  	}
      else if (!map[y][i])
	map[y][i] = new Fire(i, x);
      else if (map[y][i] && !dynamic_cast<ICrossable *>(map[y][i]))
	break;
    }
  for (int i = y + 1, j = this->_power; j >= 0; ++i, --j)
    {
      IDestroyable *destroyable = dynamic_cast<IDestroyable *>(map[i][x]);
      if (destroyable)
  	{
  	  map[i][x] = new Fire(x, i);
  	  destroyable->destroy(map);
	  break;
  	}
      else if (!map[i][x])
	map[i][x] = new Fire(x, i);
      else if (map[i][x] && !dynamic_cast<ICrossable *>(map[i][x]))
	break;
    }
  for (int i = x - 1, j = this->_power; j >= 0; --i, --j)
    {
      IDestroyable *destroyable = dynamic_cast<IDestroyable *>(map[y][i]);
      if (destroyable)
  	{
  	  map[y][i] = new Fire(i, y);
  	  destroyable->destroy(map);
	  break;
  	}
      else if (!map[y][i])
	map[y][i] = new Fire(i, y);
      else if (map[y][i] && !dynamic_cast<ICrossable *>(map[y][i]))
	break;
    }
  this->_SoundPlayer->playSound("explosion", false);
  delete this;
}

void			Bomb::update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map)
{
  this->_elapsed += clock.getElapsed();
  if (this->isExploding())
    this->destroy(map);
}

void			Bomb::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), 0.02);
}

bool			Bomb::isExploding() const
{
  return (this->_elapsed > this->_livespan);
}

void	Bomb::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}
