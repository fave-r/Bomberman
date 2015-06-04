//
// APlayer.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/src
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Tue May  5 19:56:39 2015 polydo_s
// Last update Thu Jun  4 18:51:35 2015 polydo_s
//

#include "APlayer.hh"

APlayer::APlayer(float x, float y, APlayer::eOrientation orientation)
  : AObject(x, y, 0.90, 0.90), _orientation(orientation), _delta(0.1), _speed(2), _inAnim(false)
{
  static unsigned id = 1;
  this->_id = id++;
  if (this->_model.load("./Assets/Player/marvin.fbx") == false)
    std::cerr << "Cannot load the model" << std::endl;
  if (this->_model.createSubAnim(0, "wait", 0, 0) == false)
    std::cout << "MDR" << "\n";
  if (this->_model.createSubAnim(0, "run", 36, 53) == false)
    std::cout << "MDR" << "\n";
  glm::vec3 vec(0.002, 0.002, 0.002);
  this->scale(vec);
}

void			APlayer::draw(gdl::AShader &shader)
{
  ///NE SERT A RIEN
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

  (void)clock;
  switch (this->_orientation)
    {
    case APlayer::UP:
      y -= 1;
      break;
    case APlayer::RIGHT:
      x += 1;
      break;
    case APlayer::DOWN:
      y += 1;
      break;
    case APlayer::LEFT:
      x -= 1;
      break;
    }
  if (!map[y][x])
    map[y][x] = new Bomb(x, y);
}

void			APlayer::goUp(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock)
{
  AObject		*dest;
  ICrossable		*crossable;

  if (!this->_inAnim)
    this->_inAnim = this->_model.setCurrentSubAnim("run");
  dest = map[static_cast<int>(this->_y - this->_delta)][static_cast<int>(this->_x)];
  crossable = dynamic_cast<ICrossable *>(dest);
  if (!dest || crossable)
    this->_y -= static_cast<float>(clock.getElapsed() * this->_speed);
  this->_orientation = APlayer::UP;
}

void			APlayer::goRight(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock)
{
  AObject		*dest;
  ICrossable		*crossable;

  if (!this->_inAnim)
    this->_inAnim = this->_model.setCurrentSubAnim("run");
  dest = map[static_cast<int>(this->_y + this->_h)][static_cast<int>(this->_x + this->_w + this->_delta)];
  crossable = dynamic_cast<ICrossable *>(dest);
  if (!dest || crossable)
    this->_x += static_cast<float>(clock.getElapsed() * this->_speed);
  this->_orientation = APlayer::RIGHT;
}

void			APlayer::goDown(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock)
{
  AObject		*dest;
  ICrossable		*crossable;

  if (!this->_inAnim)
    this->_inAnim = this->_model.setCurrentSubAnim("run");
  dest = map[static_cast<int>(this->_y + this->_h + this->_delta)][static_cast<int>(this->_x + this->_w)];
  crossable = dynamic_cast<ICrossable *>(dest);
  if (!dest || crossable)
    this->_y += static_cast<float>(clock.getElapsed() * this->_speed);
  this->_orientation = APlayer::DOWN;
}

void			APlayer::goLeft(std::vector<std::vector<AObject *> > &map, const gdl::Clock &clock)
{
  AObject		*dest;
  ICrossable		*crossable;

  if (!this->_inAnim)
    this->_inAnim = this->_model.setCurrentSubAnim("run");
  dest = map[static_cast<int>(this->_y)][static_cast<int>(this->_x - this->_delta)];
  crossable = dynamic_cast<ICrossable *>(dest);
  if (!dest || crossable)
    this->_x -= static_cast<float>(clock.getElapsed() * this->_speed);
  this->_orientation = APlayer::LEFT;
}

APlayer::eOrientation		APlayer::getOrientation() const
{
  return this->_orientation;
}
