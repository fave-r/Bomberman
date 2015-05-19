//
// ACharacter.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun May  3 18:57:39 2015 polydo_s
// Last update Mon May 18 11:24:38 2015 polydo_s
//

#ifndef ACHARACTER_HH
#define ACHARACTER_HH

#include <iostream>

#include <string>

#include "AElement.hh"

/**
 * @class ACharacter
 * @brief Everything that moves and play
 *
 * All the characters are elements that can actually play,
 * they have a name and an orientation
 *
 * @author Swann Polydor (polydo_s)
 * @version 0.1
 * @bug No known bugs.
 *
 * @date May 4, 2015
 */

class	ACharacter : public AElement {

public:
  /// Orientation to which the character can look
  enum eOrientation {
    UP,
    RIGHT,
    DOWN,
    LEFT
  };

protected:
  eOrientation	_orientation; //!< The direction to which the character is looking

public:

  /**
   * Construct any kind of character
   *
   * @param name player's name or monster type
   * @param orientation to where the character is looking
   */
  ACharacter(float x, float y, eOrientation orientation);

protected:
  void			move(eOrientation orientation);

public:
  void			goUp();
  void			goRight();
  void			goDown();
  void			goLeft();

public:

  /**
   * Get the character orientation
   */
  eOrientation		getOrientation() const;

public:

  /**
   * Change the orientation of any character
   *
   * @param orientation the new orientation
   */
  void	setOrientation(eOrientation orientation);
};

#endif
