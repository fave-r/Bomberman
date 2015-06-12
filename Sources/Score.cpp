//
// Score.cpp for Score in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Tue Jun  9 16:13:55 2015 Leo Thevenet
// Last update Thu Jun 11 10:50:24 2015 Leo Thevenet
//

#include "Score.hh"
#include "Error.hh"

namespace	Score
{
  void		addNewScore(const int &s, const int &p)
  {
    std::pair<int, int> a = Score::getAllScore();
    std::ofstream fichier(".score", std::ofstream::out | std::ofstream::trunc);

    if(fichier)
      {
	if (p == 1)
	  a.first += s;
	else
	  a.second += s;
	fichier << a.first << std::endl << a.second << std::endl;
	fichier.close();
      }
    else
      throw loading_error("Can't acces file .score");
  }

  std::pair<int, int> getAllScore()
  {
    std::ifstream fichier(".score", std::ifstream::in);
    int		a, b;

    if(!fichier)
      return std::make_pair(0, 0);
    fichier >> a >> b;
    fichier.close();
    return std::make_pair(a, b);
  }
};
