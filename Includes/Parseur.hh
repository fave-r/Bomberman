//
// Parseur.hh for Parseur in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Thu May 28 15:41:54 2015 Leo Thevenet
// Last update Thu Jun 11 15:41:15 2015 Leo Thevenet
//

#ifndef __PARSEUR_HH__
#define __PARSEUR_HH__

#include "Error.hh"

namespace	Parseur
{
  void		setConf(int, int, int, int, int);
  int		getX();
  int		getY();
  int		getPlayer();
  int		getIA();
  int		getDensite();
};

#endif