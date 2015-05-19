//
// ACharacter.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun May  3 18:57:39 2015 polydo_s
// Last update Tue May 19 16:09:48 2015 polydo_s
//

#ifndef ACHARACTER_HH
#define ACHARACTER_HH

#include <iostream>
#include <string>

#include "AElement.hh"

class	ACharacter : public AElement {

public:
  enum eOrientation {
    UP,
    RIGHT,
    DOWN,
    LEFT
  };

protected:
  eOrientation	_orientation;

public:
  ACharacter(float x, float y, eOrientation orientation);

protected:
  void			move(eOrientation orientation);

public:
  void			goUp();
  void			goRight();
  void			goDown();
  void			goLeft();

public:
  eOrientation		getOrientation() const;

public:
  void	setOrientation(eOrientation orientation);
};

#endif
