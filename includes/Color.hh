//
// Color.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun May  3 21:54:43 2015 polydo_s
// Last update Tue May  5 19:48:31 2015 polydo_s
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
 * the opacity
 *
 * @author Swann Polydor (polydo_s)
 * @version 0.1
 * @bug No known bugs.
 *
 * @date May 4, 2015
 */

#include <cstdint>

class	Color {

private:
  unsigned char	_r;
  unsigned char	_g;
  unsigned char	_b;
  float		_a;

public:

  /**
  * Construct a new color
  *
  * @param r the red component between 0 and 255
  * @param g the green component between 0 and 255
  * @param b the blue component between 0 and 255
  * @param a the alpha of the color between 0 and 1
  */
  Color(unsigned char r, unsigned char g, unsigned char b, float a);

public:

  /**
   * Get the red component
   */
  unsigned char	getR() const;

  /**
   * Get the green component
   */
  unsigned char	getG() const;

  /**
   * Get the blue component
   */
  unsigned char	getB() const;

  /**
   * Get the alpha component
   */
  float	       	getAlpha() const;

  /**
   * Get the color in a usable format
   */
  uint32_t	getRGBA() const;
};

#endif
