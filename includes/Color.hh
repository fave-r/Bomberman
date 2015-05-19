//
// Color.hh for Bomberman in /home/polydo_s/rendu/Bomberman/includes
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Sun May  3 21:54:43 2015 polydo_s
// Last update Tue May 19 16:11:49 2015 polydo_s
//

#ifndef COLOR_HH
#define COLOR_HH

#include <cstdint>

class	Color {

private:
  unsigned char	_r;
  unsigned char	_g;
  unsigned char	_b;
  float		_a;

public:
  Color(unsigned char r, unsigned char g, unsigned char b, float a);

public:
  unsigned char	getR() const;
  unsigned char	getG() const;
  unsigned char	getB() const;
  float	       	getAlpha() const;
  uint32_t	getRGBA() const;
};

#endif
