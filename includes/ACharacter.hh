//
// ACharacter.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun May  3 18:57:39 2015 polydo_s
// Last update Fri May 15 13:46:39 2015 polydo_s
//

#ifndef ACHARACTER_HH
#define ACHARACTER_HH

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
  std::string	_name; //!< The name of the character entity
  eOrientation	_orientation; //!< The direction to which the character is looking

public:

  /**
   * Construct any kind of character
   *
   * @param name player's name or monster type
   * @param orientation to where the character is looking
   */
  ACharacter(const std::string &name, eOrientation orientation);

public:
  void			move(eOrientation orientation);

protected:
  void			goUp();
  void			goRight();
  void			goDown();
  void			goLeft();

public:

  /**
  * Get the character name
  */
  const std::string	&getName() const;

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
