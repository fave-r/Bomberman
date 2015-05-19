//
// Model.cpp for Model.cpp in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 20:15:50 2015 clément jean
// Last update Tue May 19 20:31:43 2015 clément jean
//

#include "Model.hh"

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
  _model.pause(true);
  return true;
}

void          update(const gdl::Clock &clock)
{
  (void)clock;
}

void		Model::draw(const gdl::AShader &shader)
{
  _texture.bind();
  _model.draw(shader, getTransformation(), GL_QUADS);
}
