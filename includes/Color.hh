//
// Color.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun May  3 21:54:43 2015 polydo_s
// Last update Mon May  4 00:49:38 2015 polydo_s
//

#ifndef COLOR_HH
#define COLOR_HH

/**
 * @class Color
 * @brief Class representing RGB color
 *
 * A color is composed of three different components,
 * the red hue,
 * the green hue
 * the blue hue
 *
 * @author Swann Polydor (polydo_s)
 * @version 0.1
 * @bug No known bugs.
 *
 * @date May 4, 2015
 */
class	Color {

private:
  unsigned int	_r; //!< The red component
  unsigned int	_g; //!< The green component
  unsigned int	_b; //!< The blue component

public:

  /**
  * Construct a new color
  *
  * @param r the red component
  * @param g the green component
  * @param b the blue component
  */
  Color(unsigned int r, unsigned int g, unsigned int b);

public:

  /**
   * Get the red component
   */
  unsigned int	getR() const;

  /**
   * Get the green component
   */
  unsigned int	getG() const;

  /**
   * Get the blue component
   */
  unsigned int	getB() const;
};

#endif
