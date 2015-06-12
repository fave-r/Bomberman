//
// Bomb.cpp for Bomb.cpp in /home/jean_c/Tests/Bomberman
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 02:23:16 2015 clément jean
// Last update Fri Jun 12 00:54:54 2015 polydo_s
//

#include "Bomb.hh"

Bomb::Bomb(float x, float y, APlayer *player, const gdl::Clock &clock, int power)
  : AObject(x, y, 0.6, 0.6), _elapsed(clock.getElapsed()), _livespan(2.5), _player(player), _power(power)
{
  if (this->_model.load("./Assets/Map/bomb.fbx") == false)
    throw std::runtime_error("Cannot load the bomb");
  this->translate(glm::vec3(this->_x, 1, this->_y));
  if (this->_model.createSubAnim(0, "run", 0, 60) == false)
    throw loading_error("Can't load bomb's animation");
  this->scale(glm::vec3(0.6, 0.6, 0.6));
  this->_model.setCurrentSubAnim("run");
  this->_SoundPlayer->playSound("bombstart", false);
}

Bomb::~Bomb() {}

bool			Bomb::damage(std::vector<std::vector<AObject *> > &map, APlayer *player, int x, int y)
{
  std::list<APlayer *>::iterator it;
  for (it = this->_players.begin(); it != this->_players.end(); ++it)
    {
      if (!(*it)->isDead())
	if (static_cast<int>((*it)->getX()) == x && y == static_cast<int>((*it)->getY()))
	  (*it)->kill();
    }

  if (!map[y][x])
    {
      map[y][x] = new Fire(x, y, this->_elapsed);
      return (true);
    }
  IDestroyable *destroyable = dynamic_cast<IDestroyable *>(map[y][x]);
  if (destroyable)
    destroyable->destroy(map, player);
  return (false);
}

void			Bomb::destroy(std::vector<std::vector<AObject *> > &map, APlayer *player)
{
  map[this->_y][this->_x] = new Fire(this->_x, this->_y, this->_elapsed);
  this->damage(map, player, this->_x, this->_y);
  for (int i = this->_y - 1, j = this->_power; j > 0; --i, --j)
    if (!this->damage(map, player, this->_x, i))
      break;
  for (int i = this->_x + 1, j = this->_power; j > 0; ++i, --j)
    if (!this->damage(map, player, i, this->_y))
      break;
  for (int i = this->_y + 1, j = this->_power; j > 0; ++i, --j)
    if (!this->damage(map, player, this->_x, i))
      break;
  for (int i = this->_x - 1, j = this->_power; j > 0; --i, --j)
    if (!this->damage(map, player, i, this->_y))
      break;
  this->_SoundPlayer->playSound("explosion", false);
  player->decreaseCurrentBombs();
  delete this;
}

void			Bomb::update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map, std::list<APlayer *> &players)
{
  this->_elapsed += clock.getElapsed();
  if (this->_elapsed > this->_livespan)
    {
      this->_players = players;
      this->destroy(map, this->_player);
    }
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
