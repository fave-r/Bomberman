//
// ACharacter.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun May  3 18:57:39 2015 polydo_s
// Last update Tue May 19 23:48:08 2015 polydo_s
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
  ACharacter(float, float, eOrientation);

protected:
  void			move(eOrientation);

public:
  void			goUp();
  void			goRight();
  void			goDown();
  void			goLeft();

public:
  eOrientation		getOrientation() const;

public:
  void	setOrientation(eOrientation);
};

#endif
