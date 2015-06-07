//
// Bomb.cpp for Bomb.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 02:23:16 2015 clément jean
// Last update Sun Jun  7 02:27:04 2015 polydo_s
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
  this->scale(glm::vec3(0.9, 0.9, 0.9));
  this->_model.setCurrentSubAnim("run");
}

Bomb::~Bomb() {}

void			Bomb::destroy(std::vector<std::vector<AObject *> > &map)
{
  int	x = this->_x;
  int	y = this->_y;

  for (int i = y - 1, j = this->_power; j >= 0; --i, --j)
    {
      if (map[i][x])
	{
	  IDestroyable *destroyable = dynamic_cast<IDestroyable *>(map[i][x]);
	  if (destroyable)
	    this->destroy(map);
	  break;
	}
      else
	map[i][x] = new Fire(x, i);
    }
  map[y][x] = NULL;
  delete this;
}

void			Bomb::update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map)
{
  (void)map;
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
