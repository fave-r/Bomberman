//
// AElement.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun May  3 18:53:42 2015 polydo_s
// Last update Tue May 19 23:48:27 2015 polydo_s
//

#ifndef AELEMENT_HH
#define AELEMENT_HH

#include <vector>
#include <string>

class	AElement {
protected:
  float	_x;
  float	_y;

public:
  AElement(float, float);
  virtual ~AElement();

public:
  virtual void	draw() const = 0;
  virtual void	update(std::vector<std::vector<AElement *> >) = 0;

public:
  float	getX() const;
  float	getY() const;

public:
  void	setPosition(float, float);
};

#endif
