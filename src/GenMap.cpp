//
// GenMap.cpp for GenMap in /home/lhomme_a/rendu/Bomberman
//
// Made by Arnaud Lhomme
// Login   <lhomme_a@epitech.net>
//
// Started on  Tue May  5 14:59:51 2015 Arnaud Lhomme
// Last update Thu May 21 17:09:21 2015 Arnaud Lhomme
//

#include "GenMap.hh"

GenMap::GenMap(int x = 15, int y = 15, int players = 1) : size_x(x), size_y(y), players(players)
{

}

GenMap::~GenMap()
{
}


// 'S' = SOL
// 'W' = MURS INCASSABLES
// 'E' = MURS CASSABLES
// 'P' = PLAYER

void	GenMap::generate()
{
  srand(time(NULL));

  map.resize(size_y);
  for (int y = 0; y < size_y; y++)
    map[y].resize(size_x);

  for (int y = 0; y < size_y; y++)
    {
      for (int x = 0; x < size_x; x++)
	{
	  if (x == size_x - 1 || y == size_y - 1 || x == 0 || y == 0)
	    map[x][y] = 'W';
	  else
	    {
	      int rand_value = 0 + (int)((double)rand() / ((double)RAND_MAX + 1) * 99);

	      if ((x == 1 && y == 1) || (x == 2 && y == 1) || (x == 1 && y == 2)
		  || (x == size_x - 2 && y == size_y - 2) || (x == size_x  - 3 && y == size_y - 2) || (x == size_x - 2 && y == size_y - 3))
		{
		  map[x][y] = 'S';
		}
	      else if (rand_value > 60
		       && (map[x + 1][y - 1] != 'W'))
		map[x][y] = 'W';
	      else
		map[x][y] = 'E';
	    }
	}
    }

  map[1][1] = 'P';
  if (players == 2)
    map[size_x - 2][size_y - 2] = 'P';

  for (int y = 0; y < size_y; y++)
    {
      for (int x = 0; x < size_x; x++)
	{
	  if (map[y][x] == 'P')
	    std::cout << "\033[1;36m" << map[y][x] << " " << "\033[0m";
	  else if (map[y][x] == 'W')
	    std::cout << "\033[1;31m" << map[y][x] << " " << "\033[0m";
	  else if (map[y][x] == 'E')
	    std::cout << "\033[1;38m" << map[y][x] << " " << "\033[0m";
	  else if (map[y][x] == 'S')
	    std::cout << "\033[1;32m" << map[y][x] << " " << "\033[0m";
	  else
	    std::cout << map[y][x] << " ";

	}
      std::cout << std::endl;
    }
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

std::vector<std::vector <char> >	GenMap::getMap() const
{
  return (this->map);
}

int	main()
{
  GenMap	map(15, 15, 2);

  map.generate();
}
