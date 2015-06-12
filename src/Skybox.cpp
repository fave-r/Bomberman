//
// Skybox.cpp for Skybox.cpp in /home/jean_c/Bomberman/src
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Fri Jun 12 01:25:31 2015 clément jean
// Last update Fri Jun 12 01:27:09 2015 clément jean
//

#include "Skybox.hh"

Skybox::Skybox(float x, float y)
  : AObject(x, y, 0.6, 0.6)
{
  if (this->_model.load("./Assets/Map/Skybox.fbx") == false)
    throw std::runtime_error("Cannot load the skybox");
  /*  this->translate(glm::vec3(this->_x, 1, this->_y));
  if (this->_model.createSubAnim(0, "run", 0, 60) == false)
    throw loading_error("Can't load bomb's animation");
  this->scale(glm::vec3(0.6, 0.6, 0.6));
  this->_model.setCurrentSubAnim("run");
  this->_SoundPlayer->playSound("bombstart", false);*/
}

Skybox::~Skybox() {}

void			Skybox::draw(gdl::AShader &shader)
{
  //this->_texture.bind();
  this->_model.draw(shader, getTransformation(), 0.02);
}


void	Skybox::setModel(const gdl::Geometry &geo)
{
  (void)geo;
}
