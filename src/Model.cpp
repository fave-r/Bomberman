//
// Model.cpp for Model.cpp in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 20:15:50 2015 clément jean
// Last update Thu Jun  4 19:08:18 2015 polydo_s
//

#include "Model.hpp"

Model::Model(float x, float y) : AObject(x, y, 0.9, 0.9)
{
  if (this->_model.load("./Assets/Player/marvin.fbx") == false)
    throw std::runtime_error("Cannot load the model");
  if (this->_model.createSubAnim(0, "wait", 0, 0) == false)
    throw std::runtime_error("Cannot create wait animation");
  if (this->_model.createSubAnim(0, "run", 36, 53) == false)
    throw std::runtime_error("Cannot create run animation");
  this->scale(glm::vec3(0.002, 0.002, 0.002));
}

void		Model::update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &map)
{
  (void)clock;
  (void)map;
}

void		Model::draw(gdl::AShader &shader)
{
  this->_texture.bind();
  this->_model.draw(shader, getTransformation(), 0.03);
}
