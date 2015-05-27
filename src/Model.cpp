//
// Model.cpp for Model.cpp in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 20:15:50 2015 clément jean
<<<<<<< HEAD
// Last update Wed May 27 03:34:46 2015 clément jean
=======
// Last update Wed May 27 01:39:47 2015 polydo_s
>>>>>>> 1fd37cd6da98fca4e54495a2651555695c87ba53
//

#include "Model.hpp"

Model::Model(float x, float y) : AObject(x, y, 0.9, 0.9)
{
}

Model::~Model()
{
}

bool		Model::initialize()
{
  this->_speed = 100.0f;
  if (this->_model.load("./Assets/marvin.fbx") == false)
    {
      std::cerr << "Cannot load the model" << std::endl;
      return (false);
    }
  glm::vec3 vec(0.002, 0.002, 0.002);
  this->scale(vec);
  this->_model.pause(true);
  return true;
}

void		Model::update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map)
{
  (void)clock;
  (void)map;
}

void		Model::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), GL_QUADS);
}

<<<<<<< HEAD
void		Model::setTexture(const gdl::Texture &old)
{
  this->_texture = old;
}

void            Model::move(const int &x, const int &y, const int &z)
{
  translate(glm::vec3(x, y, z));
=======
const std::string	Model::toString()
{
  return "M";
>>>>>>> 1fd37cd6da98fca4e54495a2651555695c87ba53
}
