//
// Model.hpp for Model.hpp in /home/jean_c/Graphic
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Wed May  6 00:18:56 2015 clément jean
// Last update Thu May  7 09:26:18 2015 clément jean
//

#ifndef __MODEL_HPP__
# define __MODEL_HPP__

#include <iostream>
#include <Geometry.hh>
#include <Texture.hh>
#include <Model.hh>
#include "AObject.hpp"

class Model : public AObject
{
private:
  gdl::Texture	_texture;
  gdl::Model	_model;
  float		_speed;
public:
  Model() {}
  virtual ~Model() {}
  virtual bool initialize()
  {
   _speed = 100.0f;
   if (_texture.load("./lib/assets/marvin.fbm/Main_texture_diffuse2.tga") == false) //./lib/assets/fire_box.fbm/XPlosion.tga") == false)
      {
	std::cerr << "Cannot load the model texture" << std::endl;
        return (false);
      }
   if (_model.load("./lib/assets/marvin.fbx") == false) //./lib/assets/fire_box.FBX") == false)
      {
	std::cerr << "Cannot load the model" << std::endl;
        return (false);
      }
    _model.pause(true);
    //_model.setCurrentAnim(); // a voir avec blender
    return true;
  }
  virtual void update(gdl::Clock const &clock, gdl::Input &input)
  {
    if (input.getKey(SDLK_UP))
      {
	_model.pause(false);
	translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
      }
    else if (input.getKey(SDLK_DOWN))
      {
	_model.pause(false);
	translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
      }
    else if (input.getKey(SDLK_LEFT))
      {
	_model.pause(false);
	translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
      }
    else if (input.getKey(SDLK_RIGHT))
      {
	_model.pause(false);
	translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
      }
    else
      _model.pause(true);
  }
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock)
  {
    (void)clock;
    _texture.bind();
    _model.draw(shader, getTransformation(), GL_QUADS);
  }
};

#endif
