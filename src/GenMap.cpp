//
// GenMap.cpp for GenMap in /home/lhomme_a/rendu/Bomberman
//
// Made by Arnaud Lhomme
// Login   <lhomme_a@epitech.net>
//
// Started on  Tue May  5 14:59:51 2015 Arnaud Lhomme
// Last update Tue May 26 16:04:52 2015 Leo Thevenet
//

#include "GenMap.hh"

GenMap::GenMap(int x = 15, int y = 15, int players = 1) : size_x(x), size_y(y), players(players)
{}

GenMap::~GenMap()
{}

// 'S' = SOL
// 'W' = MURS INCASSABLES
// 'E' = MURS CASSABLES
// 'P' = PLAYER

void	GenMap::generate()
{
  srand(time(NULL));

  this->map.resize(this->size_y);
  for (int y = 0; y < this->size_y; ++y)
    this->map[y].resize(this->size_x);

  for (int y = 0; y < this->size_y; ++y)
    {
      for (int x = 0; x < this->size_x; ++x)
	{
	  if (x == this->size_x - 1 || y == this->size_y - 1 || x == 0 || y == 0)
	    map[x][y] = new Wall(x, y);
	  else
	    {
	      int rand_value = 0 + (int)((double)rand() / ((double)RAND_MAX + 1) * 99);

	      if ((x == 2 && y == 1) || (x == 1 && y == 2))
	  	map[x][y] = NULL;
	      else if ((x == this->size_x - 3 && y == this->size_y - 2)
	  	       || (x == this->size_x - 2 && y == this->size_y - 3))
	  	map[x][y] = NULL;
	      else if (rand_value > 60 && dynamic_cast<Wall *>(map[x + 1][y - 1]) == NULL)
	  	map[x][y] = new Wall(x, y);
	      else
	  	map[x][y] = new Box(x, y); // NEW BOX
	    }
	}
    }

  map[1][1] = NULL;// NEW PLAYER
  if (players == 2)
    map[this->size_x - 2][this->size_y - 2] = NULL; // NEW PLAYER
}

int	GenMap::getX() const
{
  return (this->size_x);
}

void	GenMap::setX(int _x)
{
  this->size_x = _x;
}

int	GenMap::getY() const
{
  return (this->size_y);
}

void	GenMap::setY(int _y)
{
  this->size_y = _y;
}

int	GenMap::getPlayers() const
{
  return (this->players);
}

void	GenMap::setPlayers(int _players)
{
  this->players = _players;
}

std::vector<std::vector <AObject * > >	GenMap::getMap() const
{
  return (this->map);
}
