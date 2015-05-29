//
// GenMap.hh for GenMap in /home/lhomme_a/rendu/Bomberman
//
// Made by Arnaud Lhomme
// Login   <lhomme_a@epitech.net>
//
// Started on  Tue May  5 15:00:01 2015 Arnaud Lhomme
// Last update Fri May 29 15:03:58 2015 polydo_s
//

#ifndef GENMAP_HH_
#define GENMAP_HH_

#include <iostream>
#include <random>
#include <vector>
#include <list>
#include "AObject.hh"
#include "Wall.hh"
#include "Box.hh"
#include "PhysicalPlayer.hh"

class	GenMap {

private:
  int					_width;
  int					_height;
  int					_players;
  std::vector<std::vector<AObject *> >	_map;

public:
  GenMap(int width, int height, int players);
  ~GenMap();

public:
  void	generate();

public:
  int	getWidth() const;
  int	getHeight() const;
  int					getPlayers() const;
  std::vector<std::vector <AObject * >	>getMap() const;

public:
  void	setWidth(int width);
  void	setHeight(int height);

public:
  void					setPlayers(int);
};

#endif
