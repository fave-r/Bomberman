//
// AElement.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun May  3 18:53:42 2015 polydo_s
// Last update Tue May 19 16:10:25 2015 polydo_s
//

#ifndef AELEMENT_HH
#define AELEMENT_HH

#include <string>

class	AElement {
protected:
  float	_x;
  float	_y;

public:
  AElement(float x, float y);
  virtual ~AElement();

public:
  virtual void	draw() const = 0;
  virtual void	update() = 0;

public:
  float	getX() const;
  float	getY() const;
  virtual const std::string	ToString() const;

public:
  void	setPosition(float x, float y);
};

#endif
