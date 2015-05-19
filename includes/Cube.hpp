//
// Cube.hpp for Cube.hpp in /home/jean_c/Graphic
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May  5 19:29:04 2015 clément jean
// Last update Tue May 19 19:47:15 2015 clément jean
//

#ifndef __CUBE_HPP__
# define __CUBE_HPP__

#include <iostream>
#include <Geometry.hh>
#include <Texture.hh>
#include "AObject.hpp"

class Cube : public AObject
{
  // La texture utilisee pour le cube
  // La geometrie du cube
  gdl::Geometry _geometry;
  // La vitesse de deplacement du cube
  float _speed;

public:
  gdl::Texture _texture;
  Cube()
  {
    _speed = 10.0f;
  }

  virtual ~Cube() { }

  gdl::Texture getTexture() const
  {
    return this->_texture;
  }

  gdl::Geometry getGeometry() const
  {
    return this->_geometry;
  }

  void setGeometry(gdl::Geometry old)
  {
    this->_geometry = old;
  }

  void setTexture(gdl::Texture & old)
  {
    this->_texture = old;
  }

  bool newTexture()
  {
    if (_texture.load("./lib/assets/marvin.fbm/Main_texture_diffuse2.tga") == false)
      {
	std::cerr << "Cannot load the cube texture" << std::endl;
	return (false);
      }
    return true;
  }

  virtual bool initialize()
  {
    // if (newTexture() == false)
    //   return false;
    // On charge la texture qui sera affichee sur chaque face du cube
    // on set la color d'une premiere face
    _geometry.setColor(glm::vec4(153.0 / 255.0, 51 / 255.0, 0, 1));
    // tout les pushVertex qui suivent seront de cette couleur
    // On y push les vertices d une premiere face
    _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
    // Les UVs d'une premiere face
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    // ETC ETC
    _geometry.setColor(glm::vec4(153.0 / 255.0, 51 / 255.0, 0, 1));
    _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.setColor(glm::vec4(153.0 / 255.0, 51 / 255.0, 0, 1));
    _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
    _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.setColor(glm::vec4(153.0 / 255.0, 51 / 255.0, 0, 1));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.setColor(glm::vec4(0, 1, 0, 1));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.setColor(glm::vec4(153.0 / 255.0, 51 / 255.0, 0, 1));
    _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
    _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    // Tres important, on n'oublie pas de build la geometrie pour envoyer ses informations a la carte graphique
  _geometry.build();
  return (true);
  }

  void move(int x, int y, int z)
  {
    translate(glm::vec3(x, y, z));
  }

  // Ici le cube bougera avec les fleches du clavier
  virtual void update(gdl::Clock const &clock)
  {
    // On multiplie par le temps ecoule depuis la derniere image pour que la vitesse ne depende pas de la puissance de l'ordinateur
    if (this->_input.getKey(SDLK_UP))
      translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
    if (this->_input.getKey(SDLK_DOWN))
      translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
    if (this->_input.getKey(SDLK_LEFT))
      translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
    if (this->_input.getKey(SDLK_RIGHT))
      translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
    if (this->_input.getKey(SDLK_KP_PLUS))
      translate(glm::vec3(0, -1, 0) * static_cast<float>(clock.getElapsed()) * _speed);
    if (this->_input.getKey(SDLK_KP_MINUS))
      translate(glm::vec3(0, 1, 0) * static_cast<float>(clock.getElapsed()) * _speed);

    if (this->_input.getKey(SDLK_q))
      rotate(glm::vec3(0, -1, 0) * static_cast<float>(clock.getElapsed()) * _speed, 5);
    if (this->_input.getKey(SDLK_d))
      rotate(glm::vec3(0, 1, 0) * static_cast<float>(clock.getElapsed()) * _speed, 5);

    if (this->_input.getKey(SDLK_z))
      rotate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed, 5);
    if (this->_input.getKey(SDLK_s))
      rotate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed, 5);
  }

  virtual void draw(gdl::AShader &shader)
  {
    // On bind la texture pour dire que l'on veux l'utiliser
    // std::cout << "d" << std::endl;
    _texture.bind();
    // std::cout << "f" << std::endl;
    // Et on dessine notre cube
    // std::cout << "g" << std::endl;
    _geometry.draw(shader, getTransformation(), GL_QUADS);
    // std::cout << "xx" << std::endl;
  }
};

#endif
