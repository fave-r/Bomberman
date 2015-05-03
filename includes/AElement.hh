//
// AElement.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun May  3 18:53:42 2015 polydo_s
// Last update Mon May  4 00:53:34 2015 polydo_s
//

#ifndef AELEMENT_HH
#define AELEMENT_HH

/**
 * @class AElement
 * @brief Base class of Bomberman's element
 * 
 * All the elements are represented by a position (x, y),
 * they are also drawable and visible.

 * We also added getters and setters to be able to manipulate,
 * thoses data.
 *
 * @author Swann Polydor (polydo_s)
 * @version 0.1
 * @bug No known bugs
 *
 * @date May 4, 2015
 */

class	AElement {
protected:
  unsigned int	_x; //!< The x position of any element
  unsigned int	_y; //!< The y position of any element

public:

  /**
   * Construct any kind of element
   *
   * @param x position
   * @param y position
   */
  AElement(unsigned int x, unsigned int y);

public:
  /**
   * Draw any kind of element
   */
  virtual void	draw() const = 0;

public:
  /**
   * Get the x position of any element
   */
  int	getX() const;

  /**
   * Get the y position of any element
   */
  int	getY() const;

public:
  /**
   * Set the position to any element
   *
   * @param x the new x position
   * @param y the new y position
   */
  void	setPosition(unsigned int x, unsigned int y);
};

#endif
