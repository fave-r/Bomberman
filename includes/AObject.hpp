//
// AObject.hpp for AObject.hpp in /home/jean_c/Graphic
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May  5 19:27:04 2015 clément jean
// Last update Sat May  9 18:24:01 2015 clément jean
//

#ifndef __AOBJECT_HPP__
# define __AOBJECT_HPP__

#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

class AObject
{
public:
  AObject() :
    _position(0, 0, 0), // On initialise la position a 0
    _rotation(0, 0, 0), // pareil pour la rotation
    _scale(1, 1, 1) // l'echelle est mise a 1
  {
  }
  virtual ~AObject() {}
  // La fonction initialize charge l'objet ou le construit
  virtual bool initialize()
  {
    return (true);
  }
  // La fonction update sert a gerer le comportement de l'objet
  virtual void update(gdl::Clock const &clock, gdl::Input &input)
  {
    (void)clock;
    (void)input;
  }
  // La fonction draw sert a dessiner l'objet
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;
  void translate(glm::vec3 const &v)
  {
    _position += v;
  }
  void	SetPos(glm::vec3 const &v)
  {
    _position.x = v.x;
    _position.y = v.y;
    _position.z = v.z;
  }
  void rotate(glm::vec3 const& axis, float angle)
  {
    _rotation += axis * angle;
  }
  void scale(glm::vec3 const& scale)
  {
    _scale *= scale;
  }
  glm::mat4 getTransformation()
  {
    glm::mat4 transform(1); // On cree une matrice identite
    // On applique ensuite les rotations selon les axes x, y et z
    transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
    transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
    transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
    // On effectue ensuite la translation
    transform = glm::translate(transform, _position);
    // Et pour finir, on fait la mise a l'echelle
    transform = glm::scale(transform, _scale);
    return (transform);
  }
protected:
  glm::vec3 _position;
  glm::vec3 _rotation;
  glm::vec3 _scale;
};

#endif
