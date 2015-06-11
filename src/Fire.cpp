
//
// Fire.cpp for Fire.cpp in /home/jean_c/Tests/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri May 29 17:27:42 2015 clément jean
// Last update Fri Jun 12 00:58:03 2015 polydo_s
//

#include "Fire.hh"

Fire::Fire(float x, float y, double elapsed)
  :AObject(x, y, 0.99, 0.99), _elapsed(elapsed), _livespan(elapsed + 1)
{
  this->scale(glm::vec3(1, 1, 1));
  this->translate(glm::vec3(this->_x, 1, this->_y));
}

Fire::~Fire() {}

void		Fire::update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map, std::list<APlayer *> &players)
{
  (void)players;
  this->_elapsed += clock.getElapsed();
  if (this->_elapsed > this->_livespan)
    map[this->_y][this->_x] = NULL;
}

void		Fire::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_geometry.draw(shader, getTransformation(), GL_QUADS);
}

void          Fire::setModel(const gdl::Geometry &geo)
{
  this->_geometry = geo;
}

void          Fire::affect(APlayer *player)
{
  player->kill();
}
