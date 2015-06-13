//
// Score.hh for Score in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Tue Jun  9 16:14:18 2015 Leo Thevenet
// Last update Sat Jun 13 18:38:29 2015 clément jean
//

#ifndef __SCORE_HH__
#define __SCORE_HH__

#include <fstream>
#include <iostream>
#include <vector>

namespace Score
{
  void			addNewScore(const int &, const int &);
  std::pair<int, int>	getAllScore();
};

#endif
