//
// Model.cpp for Model.cpp in /home/jean_c/Tests/Bomberman/includes
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May 19 20:15:50 2015 clément jean
// Last update Mon Jun  1 11:33:28 2015 Leo Thevenet
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
  if (this->_model.load("./Assets/marvin2.fbx") == false) // EN ATTENDANT DE REGLER LE SETMODEL
    {
      std::cerr << "Cannot load the model" << std::endl;
      return (false);
    }
  if (this->_model.createSubAnim(0, "wait", 0, 36) == false)
    std::cout << "MDR" << "\n";
  if (this->_model.createSubAnim(0, "run", 36, 53) == false)
    std::cout << "MDR" << "\n";
  glm::vec3 vec(0.002, 0.002, 0.002);
  this->scale(vec);
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

void		Model::setTexture(const gdl::Texture &old)
{
  this->_texture = old;
}

void		Model::setModel(const gdl::Model &old)
{
  (void)old;
  //this->_model = old;
}

void            Model::move(const int &x, const int &y, const int &z)
{
  translate(glm::vec3(x, y, z));
}

const std::string	Model::toString()
{
  return "M";
}
