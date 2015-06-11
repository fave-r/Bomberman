//
// APlayer.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/src
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:56:39 2015 polydo_s
// Last update Fri Jun 12 00:59:46 2015 clément jean
//

#include "APlayer.hh"
#include "Bomb.hh"

APlayer::APlayer(float x, float y, APlayer::eOrientation orientation)
  : AObject(x, y, 0.90, 0.90), _orientation(orientation), _delta(0.6), _speed(2), _inAnim(false)
{
  static unsigned id = 1;
  this->_score = 0;
  this->_id = id++;
  if (this->_id == 1)
    {
      if (this->_model.load("./Assets/Player/marvin.dae") == false)
	throw exec_error("APlayer : Cannot load the model");
    }
  else
    {
      if (this->_model.load("./Assets/Player/marvin2.dae") == false)
	throw exec_error("APlayer : Cannot load the model");
    }
  if (this->_model.createSubAnim(0, "wait", 0, 0) == false)
    throw exec_error("APlayer : Cannot wait");
  if (this->_model.createSubAnim(0, "run", 36, 53) == false)
    throw exec_error("APlayer : Cannot run");
  glm::vec3 vec(0.002, 0.002, 0.002);
  this->scale(vec);
}

APlayer::~APlayer() {}

void			APlayer::wait()
{
  this->_inAnim = false;
  this->_model.setCurrentSubAnim("wait");
}

void			APlayer::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), 0.03);
}

void			APlayer::move(const int &x, const int &y, const int &z)
{
  translate(glm::vec3(x, y, z));
}

void			APlayer::putBomb(std::vector<std::vector<AObject *> >&map, const gdl::Clock &clock)
{
  int x = this->_x + 0.5;
  int y = this->_y + 0.5;

  if (!map[y][x])
    {
      map[y][x] = new Bomb(x, y, this, clock, 3);
      this->wait();
    }
}

void			APlayer::goUp(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock)
{
  float y = this->_y;
  AObject *src;
  AObject *dest;

  if (!this->_inAnim)
    this->_inAnim = this->_model.setCurrentSubAnim("run");

  src = map[this->_y + this->_h / 2][this->_x + this->_w / 2];
  dest = map[this->_y + this->_h / 2 - this->_delta][this->_x + this->_w / 2];
  this->_y -= clock.getElapsed() * this->_speed;
  if (dest && dest != src)
    {
      ICrossable *crossable = dynamic_cast<ICrossable *>(dest);
      if (crossable)
	crossable->affect(this);
      else if (this->isColliding(dest))
	this->_y = y;
    }
  this->_orientation = APlayer::UP;
}

void			APlayer::goRight(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock)
{
  float x = this->_x;
  AObject *src;
  AObject *dest;

  if (!this->_inAnim)
    this->_inAnim = this->_model.setCurrentSubAnim("run");

  src = map[this->_y + this->_h / 2][this->_x + this->_w / 2];
  dest = map[this->_y + this->_h / 2][this->_x + this->_w / 2 + this->_delta];
  this->_x += clock.getElapsed() * this->_speed;
  if (dest && dest != src)
    {
      ICrossable *crossable = dynamic_cast<ICrossable *>(dest);
      if (crossable)
	crossable->affect(this);
      else if (this->isColliding(dest))
	  this->_x = x;
    }
  this->_orientation = APlayer::RIGHT;
}

void			APlayer::goDown(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock)
{
  float y = this->_y;
  AObject *src;
  AObject *dest;

  if (!this->_inAnim)
    this->_inAnim = this->_model.setCurrentSubAnim("run");

  src = map[this->_y + this->_h / 2][this->_x + this->_w / 2];
  dest = map[this->_y + this->_h / 2 + this->_delta][this->_x + this->_w / 2];
  this->_y += clock.getElapsed() * this->_speed;
  if (dest && dest != src)
    {
      ICrossable *crossable = dynamic_cast<ICrossable *>(dest);
      if (crossable)
	crossable->affect(this);
      else if (this->isColliding(dest))
	this->_y = y;
    }
  this->_orientation = APlayer::DOWN;
}

void			APlayer::goLeft(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock)
{
  float x = this->_x;
  AObject *src;
  AObject *dest;

  if (!this->_inAnim)
    this->_inAnim = this->_model.setCurrentSubAnim("run");
  src = map[this->_y + this->_h / 2][this->_x + this->_w / 2];
  dest = map[this->_y + this->_h / 2][this->_x + this->_w / 2 - this->_delta];
  this->_x -= clock.getElapsed() * this->_speed;
  if (dest && dest != src)
    {
      ICrossable *crossable = dynamic_cast<ICrossable *>(dest);
      if (crossable)
	crossable->affect(this);
      else if (this->isColliding(dest))
	this->_x = x;
    }
  this->_orientation = APlayer::LEFT;
}

APlayer::eOrientation		APlayer::getOrientation() const
{
  return this->_orientation;
}

void				APlayer::updateScore(int nb)
{
.  this->_score += nb;
  std::cout << this->_score << "\n";
}
