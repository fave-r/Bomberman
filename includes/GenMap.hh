//
// GenMap.hh for GenMap in /home/lhomme_a/rendu/Bomberman
// 
// Made by Arnaud Lhomme
// Login   <lhomme_a@epitech.net>
// 
// Started on  Tue May  5 15:00:01 2015 Arnaud Lhomme
// Last update Thu May 21 15:47:47 2015 Arnaud Lhomme
//

#ifndef GENMAP_HH_
#define GENMAP_HH_

#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>
#include <time.h>

class	GenMap
{
private:
  int					size_x;
  int					size_y;
  int					players;
  std::vector<std::vector<char> >	map;

public:
  GenMap(int x, int y, int players);
  ~GenMap();

  int	getX() const;
  void	setX(int);

  int	getY() const;
  void	setY(int);

  int		getPlayers() const;
  void		setPlayers(int);

  std::vector<std::vector <char> >	getMap() const;

  void	generate();
};

#endif
