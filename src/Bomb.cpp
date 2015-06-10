//
// Bomb.cpp for Bomb.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 02:23:16 2015 clément jean
<<<<<<< HEAD
// Last update Wed Jun 10 02:27:53 2015 polydo_s
=======
// Last update Mon Jun  8 16:05:59 2015 clément jean
>>>>>>> ec6aa9191970d65097f2e549208f53e0c22de69a
//

#include <unistd.h>
#include "Bomb.hh"

Bomb::Bomb(float x, float y, APlayer *player, const gdl::Clock &clock, int power)
  : AObject(x, y, 0.6, 0.6), _elapsed(clock.getElapsed()), _livespan(2.5), _player(player), _power(power)
{
  if (this->_model.load("./Assets/Map/bomb.fbx") == false)
    throw std::runtime_error("Cannot load the bomb");
  this->translate(glm::vec3(this->_x, 1, this->_y));
  if (this->_model.createSubAnim(0, "run", 0, 60) == false)
    throw std::runtime_error("Can't load bomb's animation");
<<<<<<< HEAD
  this->scale(glm::vec3(0.6, 0.6, 0.6));
=======
  this->scale(glm::vec3(0.7, 0.7, 0.7));
>>>>>>> ec6aa9191970d65097f2e549208f53e0c22de69a
  this->_model.setCurrentSubAnim("run");
  this->_SoundPlayer->playSound("bombstart", false);
}

Bomb::~Bomb() {}

bool			Bomb::damage(std::vector<std::vector<AObject *> > &map, int x, int y)
{
  IDestroyable *destroyable = dynamic_cast<IDestroyable *>(map[y][x]);
  if (destroyable)
    {
      destroyable->destroy(map);
      map[y][x] = new Fire(x, y, this->_elapsed);
    }
  else if (!map[y][x])
    {
      map[y][x] = new Fire(x, y, this->_elapsed);
      return (true);
    }
<<<<<<< HEAD
  return (false);
}

void			Bomb::destroy(std::vector<std::vector<AObject *> > &map)
{
  map[this->_y][this->_x] = new Fire(this->_x, this->_y, this->_elapsed);
  for (int i = this->_y - 1, j = this->_power; j > 0; --i, --j)
    if (!this->damage(map, this->_x, i))
      break;
  for (int i = this->_x + 1, j = this->_power; j > 0; ++i, --j)
    if (!this->damage(map, i, this->_y))
      break;
  for (int i = this->_y + 1, j = this->_power; j > 0; ++i, --j)
    if (!this->damage(map, this->_x, i))
      break;
  for (int i = this->_x - 1, j = this->_power; j > 0; --i, --j)
    if (!this->damage(map, i, this->_y))
      break;
=======
  this->_SoundPlayer->playSound("explosion", false);
  delete this;
>>>>>>> ec6aa9191970d65097f2e549208f53e0c22de69a
}

void			Bomb::update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map)
{
  this->_elapsed += clock.getElapsed();
  if (this->_elapsed > this->_livespan)
    this->destroy(map);
}

void			Bomb::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), 0.02);
}


void	Bomb::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}
