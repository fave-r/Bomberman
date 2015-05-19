//
// Visual.hpp for Visual in /home/theven_l/Dropbox/Bomberman-Graphic/Includes
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Sat May  9 18:49:54 2015 Leo Thevenet
// Last update Tue May 19 15:53:14 2015 Leo Thevenet
//

#ifndef __VISUAL_HPP__
#define __VISUAL_HPP__

#include <vector>
#include <Game.hh>
#include <SdlContext.hh>
#include <AShader.hh>
#include <BasicShader.hh>
#include "Model.hpp"
#include "Cube.hpp"
#include "AObject.hpp"

class Visual : public gdl::Game
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

    if (!_context.start(1910, 1070, "My bomberman!"))
      return false;
    glEnable(GL_DEPTH_TEST);
    if (!_shader.load("./lib/shaders/basic.fp", GL_FRAGMENT_SHADER)
	|| !_shader.load("./lib/shaders/basic.vp", GL_VERTEX_SHADER)
	|| !_shader.build())
      return false;

    projection = glm::perspective(60.0f, 1000.0f / 1000.0f, 0.1f, 2000.0f);
    transformation = glm::lookAt(glm::vec3(0, 30, 30), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    h = 30;
    l = 30;
    dg = 0;
    _shader.bind();
    _shader.setUniform("view", transformation);
    _shader.setUniform("projection", projection);
    gdl::Texture _texture;
    if (_texture.load("./lib/assets/marvin.fbm/Main_texture_diffuse2.tga") == false)
      {
	std::cerr << "Cannot load the cube texture" << std::endl;
	return (false);
      }

    Cube	*old = new Cube;
    Cube	*model;
    old->initialize();
    old->newTexture();
    _objects.push_back(old);

    float x = -(this->x / 2);
    float y;
    // std::cout << "aa" << std::endl;

    for (x = x; x <= (this->x / 2); x++)
      {
	y = -(this->y / 2);
	model = new Cube;
	// model->setGeometry(old->getGeometry());
	model->move(y, 1, x);
	// model->setTexture(old->getTexture());
	_objects.push_back(model);
	// std::cout << "bb" << std::endl;

	for (y = y; y <= (this->y / 2); y++)
	  {
	    if (x == -(this->x / 2) || x == (this->x / 2))
	      {
		model = new Cube;
		// model->setGeometry(old->getGeometry());
		// model->setTexture(old->getTexture());
		model->move(y, 1, x);
		_objects.push_back(model);
	      }
	    model = new Cube;
	    //  model->setGeometry(old->getGeometry());
	    // model->setTexture(old->getTexture());
	    model->move(y, 0, x);
	    _objects.push_back(model);

	    // std::cout << "xx" << std::endl;
	    //draw();
	    // std::cout << "zz" << std::endl;
	  }

	model = new Cube;
	//model->setGeometry(old->getGeometry());
	// model->setTexture(old->getTexture());
	model->move(y - 1, 1, x);
	_objects.push_back(model);
      }
    for (size_t i = 0; i < _objects.size(); ++i)
      {
	if (_objects[i]->initialize() == false)
	  return false;
	((Cube *)_objects[i])->setTexture(old->_texture);
      }
    draw();
    return true;
  }

  bool update()
  {
    if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
      return false;
    _context.updateClock(_clock);
    _context.updateInputs(_input);

    glm::mat4 transformation;

    if (_input.getKey(SDLK_KP_PLUS))
      h = h + 1;// * static_cast<float>(clock.getElapsed()) * _speed;
    else if (_input.getKey(SDLK_KP_MINUS))
      h = h - 1;// * static_cast<float>(clock.getElapsed()) * _speed;
    else if (_input.getKey(SDLK_UP))
      l = (l == -1) ? 1 : l + 1;
    else if (_input.getKey(SDLK_DOWN))
      l = (l == 1) ? -1 : l - 1;
    else if (_input.getKey(SDLK_LEFT))
      dg = dg - 1;
    else if (_input.getKey(SDLK_RIGHT))
      dg = dg + 1;
    else
      for (size_t i = 0; i < _objects.size(); ++i)
	_objects[i]->update(_clock, _input);
    transformation = glm::lookAt(glm::vec3(dg, h, l), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

    _shader.bind();
    _shader.setUniform("view", transformation);
    return true;
  }

  void draw()
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // std::cout << "1" << std::endl;
    _shader.bind();
    // std::cout << "2" << std::endl;
    for (size_t i = 0; i < _objects.size(); ++i)
      _objects[i]->draw(_shader, _clock);
    // std::cout << "3" << std::endl;
    _context.flush();
  }

  ~Visual()
  {
    for (size_t i = 0; i < _objects.size(); ++i)
      delete _objects[i];
  }
};

#endif
