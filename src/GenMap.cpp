//
// GenMap.cpp for GenMap in /home/lhomme_a/rendu/Bomberman
//
// Made by Arnaud Lhomme
// Login   <lhomme_a@epitech.net>
//
// Started on  Tue May  5 14:59:51 2015 Arnaud Lhomme
// Last update Sun May 31 15:50:26 2015 Leo Thevenet
//

#include "GenMap.hh"

GenMap::GenMap(int width = 10, int height = 10, int players = 1)
  : _width(width), _height(height), _players(players)
{}

GenMap::~GenMap()
{}

void	GenMap::generate()
{
  std::random_device generator;
  std::uniform_int_distribution<int> distribution(1, 100);

  this->_map.resize(this->_height);
  for (int y = 0; y < this->_height; ++y)
    {
      this->_map[y].resize(this->_width);
      for (int x = 0; x < this->_width; ++x)
	{
	  if (!x || !y || x == this->_width - 1 || y == this->_height - 1)
	    this->_map[y][x] = new Wall(x, y);
	  else
	    {
	      int rand_value = distribution(generator);

	      if ((x == 2 && y == 1) || (x == 1 && y == 2))
	  	this->_map[y][x] = NULL;
	      else if ((x == this->_width - 3 && y == this->_height - 2)
	  	       || (x == this->_width - 2 && y == this->_height - 3))
	  	this->_map[y][x] = NULL;
	      else if (rand_value > (100 - Parseur::getDensite()) && !dynamic_cast<Wall *>(this->_map[y][x - 1]) && !dynamic_cast<Wall *>(this->_map[y - 1][x + 1]))
		this->_map[y][x] = new Wall(x, y);
	      else
	  	this->_map[y][x] = new Box(x, y);
	    }
	}
    }

  this->_map[1][1] = NULL;// NEW PLAYER
  if (this->_players == 2)
    this->_map[this->_height - 2][this->_width - 2] = NULL; // NEW PLAYER
}

int	GenMap::getWidth() const
{
  return (this->_width);
}

int	GenMap::getHeight() const
{
  return (this->_height);
}

int	GenMap::getPlayers() const
{
  return (this->_players);
}

std::vector<std::vector <AObject * > >	GenMap::getMap() const
{
  return (this->_map);
}

void	GenMap::setWidth(int width)
{
  this->_width = width;
}

void	GenMap::setHeight(int height)
{
  this->_height = height;
}

void	GenMap::setPlayers(int players)
{
  this->_players = players;
}
