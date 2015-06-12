//
// Score.hh for Score in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Tue Jun  9 16:14:18 2015 Leo Thevenet
// Last update Thu Jun 11 10:20:20 2015 Leo Thevenet
//

#ifndef __SCORE_HH__
#define __SCORE_HH__

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Bomberman.hh"

namespace Score
{
  void addNewScore(const int &, const int &);
  std::pair<int, int> getAllScore();
};

#endif
