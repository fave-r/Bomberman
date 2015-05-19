//
// Model.cpp for Model.cpp in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 20:15:50 2015 clément jean
// Last update Tue May 19 21:57:09 2015 clément jean
//

#include "Model.hpp"

Model::Model()
{
}

Model::~Model()
{
}

bool		Model::initialize()
{
  this->_speed = 100.0f;
  if (this->_texture.load("./lib/assets/marvin.fbm/Main_texture_diffuse2.tga") == false)
    {
      std::cerr << "Cannot load the model texture" << std::endl;
      return (false);
    }
  if (this->_model.load("./lib/assets/marvin.fbx") == false)
    {
      std::cerr << "Cannot load the model" << std::endl;
      return (false);
    }
  this->_model.pause(true);
  return true;
}

void		Model::update(const gdl::Clock &clock)
{
  (void)clock;
}

void		Model::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), GL_QUADS);
}
