//
// Visual.hpp for Visual in /home/theven_l/Dropbox/Bomberman-Graphic/Includes
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Sat May  9 18:49:54 2015 Leo Thevenet
// Last update Tue May 19 19:43:56 2015 Leo Thevenet
//

#ifndef __VISUAL_HPP__
#define __VISUAL_HPP__

#include <vector>
#include <Game.hh>
#include <SdlContext.hh>
#include <AShader.hh>
#include <BasicShader.hh>
#include "Cube.hpp"
#include "AObject.hpp"

class Bomberman : public gdl::Game
{
  gdl::SdlContext _context;
  gdl::Clock _clock;
  gdl::Input _input;
  gdl::BasicShader _shader;
  std::vector<AObject*> _objects;
  int x, y;
  int h, l, dg;
public:
  Visual(int x, int y)
  {
    this->x = x;
    this->y = y;
  }

  bool initialize()
  {
    glm::mat4 projection;
    glm::mat4 transformation;
    gdl::Texture _texture;

    if (!_context.start(1910, 1070, "My bomberman!"))
      return false;
    glEnable(GL_DEPTH_TEST);
    if (!this->_shader.load("./lib/shaders/basic.fp", GL_FRAGMENT_SHADER)
	|| !this->_shader.load("./lib/shaders/basic.vp", GL_VERTEX_SHADER)
	|| !this->_shader.build())
      return false;

    projection = glm::perspective(60.0f, 1000.0f / 1000.0f, 0.1f, 2000.0f);
    transformation = glm::lookAt(glm::vec3(0, 30, 30), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    this->_shader.bind();
    this->_shader.setUniform("view", transformation);
    this->_shader.setUniform("projection", projection);

    Cube	*old = new Cube;
    Cube	*model;
    old->initialize();
    old->newTexture();
    _objects.push_back(old);

    float x = -(this->x / 2);
    float y;
    for (x = x; x <= (this->x / 2); x++)
      {
	y = -(this->y / 2);
	model = new Cube;
	model->move(y, 1, x);
	_objects.push_back(model);
	for (y = y; y <= (this->y / 2); y++)
	  {
	    if (x == -(this->x / 2) || x == (this->x / 2))
	      {
		model = new Cube;
		model->move(y, 1, x);
		_objects.push_back(model);
	      }
	    model = new Cube;
	    model->move(y, 0, x);
	    _objects.push_back(model);
	  }
	model = new Cube;
	model->move(y - 1, 1, x);
	_objects.push_back(model);
      }
    for (size_t i = 0; i < _objects.size(); ++i)
      {
	if (_objects[i]->initialize() == false)
	  return false;
	((Cube *)_objects[i])->setTexture(_texture);
      }
    draw();
    return true;
  }

  bool update()
  {
    if (this->_input.getKey(SDLK_ESCAPE) || this->_input.getInput(SDL_QUIT))
      return false;
    this->_context.updateClock(_clock);
    this->_context.updateInputs(_input);

    for (size_t i = 0; i < this->_objects.size(); ++i)
      this->_objects[i]->update(this->_clock, this->_input);

    this->_shader.bind();
    this->_shader.setUniform("view", transformation);
    return true;
  }

  void draw()
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    this->_shader.bind();
    for (size_t i = 0; i < this->_objects.size(); ++i)
      this->_objects[i]->draw(this->_shader, this->_clock);
    this->_context.flush();
  }

  ~Visual()
  {
    for (size_t i = 0; i < _objects.size(); ++i)
      delete _objects[i];
  }
};

#endif
