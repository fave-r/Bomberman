//
// Score.cpp for Score in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Tue Jun  9 16:13:55 2015 Leo Thevenet
// Last update Tue Jun  9 17:12:02 2015 Leo Thevenet
//

#include "Score.hh"

namespace	Score
{
  void		addNewScore(const int &s)
  {
    std::ofstream fichier(".score", std::ofstream::out | std::ofstream::app);

    if(fichier)
      {
	fichier << s << std::endl;
	fichier.close();
      }
    else
      throw std::runtime_error("No score");
  }

  std::vector<int> getAllScore()
  {
    std::ifstream fichier(".score", std::ifstream::in);
    std::vector<int> _all;

    if(!fichier)
      return _all;

    int a;
    while (fichier.good())
      {
	fichier >> a;
	_all.push_back(a);
      }
    return _all;
  }
};
