//
// GenMap.cpp for GenMap in /home/lhomme_a/rendu/Bomberman
// 
// Made by Arnaud Lhomme
// Login   <lhomme_a@epitech.net>
// 
// Started on  Tue May  5 14:59:51 2015 Arnaud Lhomme
// Last update Tue May 19 15:16:44 2015 polydo_s
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
 
  for (int x = 0; x < size_x; x++) 
    for (int y = 0; y < size_y; y++) 
      map[y][x] = 'W'; 

  drillers.push_back(std::make_pair(size_x / 2, size_y / 2));
  while (drillers.size() > 0)
    {
      std::list<std::pair<int,int> >::iterator	it_begin, it_end;
      it_begin = drillers.begin();
      it_end = drillers.end();

      while (it_begin != it_end)
	{
	  bool	remove_driller = false;
	  int	rand_value = rand() % 4;
	  if (rand_value == 0)
	    {
	      (*it_begin).second -= 2;
	      if ((*it_begin).second < 0 || map[(*it_begin).second][(*it_begin).first] != 'W')
		remove_driller = true;
	      else
		map[(*it_begin).second + 1][(*it_begin).first] = 'S';
	    }
	  else if (rand_value == 1)
	    {
	      (*it_begin).second += 2;
	      if ((*it_begin).second >= size_y || map[(*it_begin).second][(*it_begin).first] != 'W')
		remove_driller = true;
	      else
		map[(*it_begin).second - 1][(*it_begin).first] = 'S';
	    }
	  else if (rand_value == 2)
	    {
	      (*it_begin).first -= 2;
	      if ((*it_begin).first < 0 || map[(*it_begin).second][(*it_begin).first] != 'W')
		remove_driller = true;
	      else
		map[(*it_begin).second][(*it_begin).first + 1] = 'S';
	    }
	  else if (rand_value == 3)
	    {
	      (*it_begin).first += 2;
	      if ((*it_begin).first >= size_x || map[(*it_begin).second][(*it_begin).first] != 'W')
		remove_driller = true;
	      else
		map[(*it_begin).second][(*it_begin).first - 1] = 'S';
	    }

	  if (remove_driller)
	    it_begin = drillers.erase(it_begin);
	  else 
	    { 
	      drillers.push_back(std::make_pair((*it_begin).first, (*it_begin).second)); 

	      drillers.push_back(std::make_pair((*it_begin).first, (*it_begin).second));

	      map[(*it_begin).second][(*it_begin).first] = 'S';
	      ++it_begin;
	    } 

	}
    }

  int	x;
  int	y;
  for (x = 0, y = 0; map[x][y] != 'S'; x++, y++)
    ;
  map[x][y] = 'P';

  if (players == 2)
    {
      for (x = size_x - 1, y = size_y - 1; map[x][y] != 'S'; x--, y--)
	;
      map[x][y] = 'P';
    }

  int dens = size_y * size_x / 8;
  while (dens > 0)
    {
      int	rand_x = rand() % size_x;
      int	rand_y = rand() % size_y;
      if (map[rand_x][rand_y] != 'E' && map[rand_x][rand_y] != 'P')
	{
	  if ((rand_x > 0 && map[rand_x - 1][rand_y] == 'S')
	      || (rand_x < size_x - 1 && map[rand_x + 1][rand_y] == 'S')
	      || (rand_y > 0 && map[rand_x][rand_y - 1] == 'S')
	      || (rand_y < size_y - 1 && map[rand_x][rand_y + 1] == 'S'))
	    {
	      map[rand_x][rand_y] = 'E';
	      dens--;
	    }
	}
    }


  for (int y = 0; y < size_y; y++) 
    {
      for (int x = 0; x < size_x; x++) 
	{ 
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

  /*char	**GenMap::getMap() const
    {
    return (this->map);
    }*/

  std::vector<std::vector <char> >	GenMap::getMap() const
  {
    return (this->map);
  }

  int	main()
  {
    GenMap	map(30, 30, 2);

    map.generate();
  }
