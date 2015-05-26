//
// Cube.hpp for Cube.hpp in /home/jean_c/Graphic
//
// Made by clément jean
// Login   <jean_c@epitech.net>
//
// Started on  Tue May  5 19:29:04 2015 clément jean
// Last update Tue May 26 23:35:35 2015 polydo_s
//

#ifndef __CUBE_HPP__
# define __CUBE_HPP__

#include <iostream>
#include <Geometry.hh>
#include <Texture.hh>
#include "AObject.hh"
#include "IUpdatable.hh"

class Cube : public AObject, public IUpdatable
{
public:
  Cube(float x, float y);
  virtual ~Cube();
  const gdl::Texture	&getTexture() const;
  const gdl::Geometry	&getGeometry() const;
  void			setGeometry(const gdl::Geometry &old);
  virtual void	        setTexture(const gdl::Texture &old);
  virtual bool		newTexture();
  void			move(const int &x, const int &y, const int &z);
  //  virtual void		update(const gdl::Clock &clock);
  virtual void		draw(gdl::AShader &shader);
  virtual void		update(const gdl::Clock &clock, std::vector<std::vector<AObject *> > &);
  virtual bool          initialize();
  // /!\ TO CHANGE
  gdl::Texture	_texture;
private:
  gdl::Geometry _geometry;
  float		_speed;
};

#endif
