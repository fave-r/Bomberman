//
// Map.cpp for Bomberman in /home/polydo_s/rendu/Bomberman/src
//
// Made by polydo_s
// Login   <polydo_s@epitech.net>
//
// Started on  Thu Jun  4 22:36:52 2015 polydo_s
// Last update Sun Jun 14 15:49:01 2015 polydo_s
//

#include "Map.hh"

std::list<APlayer *> Map::spawnPlayers(std::vector<std::vector<AObject *> > &map)
{
  int physical = Parseur::getPlayer();
  int artificial = Parseur::getIA();

  if ((physical + artificial) * 9 > (Parseur::getY() - 2) * (Parseur::getX() - 2))
    throw std::runtime_error("Not enough space to spawn players");

  std::vector<std::vector<bool> > zone(Parseur::getY(), std::vector<bool>(Parseur::getX(), true));
  std::list<APlayer *> players;
  std::random_device generator;
  std::uniform_int_distribution<int> distribution(0, zone.size() * zone[0].size());

  for (int i = 0; i < physical + artificial; ++i)
    {
      int random = distribution(generator);
      unsigned int y = 1;
      unsigned int x = 0;
      while (random >= 0)
	{
	  ++x;
	  if (x + 2 == zone[y].size())
	    {
	      x = 1;
	      ++y;
	    }
	  if (y + 2 == zone.size())
	    {
	      x = 1;
	      y = 1;
	    }
	  if (zone[y][x])
	    --random;
	}
      map[y][x] = NULL;
      if (x > map[0].size() / 2)
	map[y][x-1] = NULL;
      else
	map[y][x+1] = NULL;
      if (y > map.size() / 2)
	map[y-1][x] = NULL;
      else
	map[y+1][x] = NULL;
      if (i < physical)
	players.push_back(new PhysicalPlayer(x, y, static_cast<APlayer::eOrientation>(distribution(generator) % 4)));
      else
       	players.push_back(new ArtificialPlayer(x, y, static_cast<APlayer::eOrientation>(distribution(generator) % 4)));

      for (unsigned int j = y - 1, k = 0; k < 3; ++j, ++k)
	for (unsigned int l = x - 1, m = 0; m < 3; ++l, ++m)
	  if (j > 0 && j < zone.size() && l > 0 && l < zone[j].size())
	    zone[j][l] = false;
    }
  return (players);
}

std::vector<std::vector<AObject *> > Map::generate()
{
  std::vector<std::vector<AObject *> > map(Parseur::getY(), std::vector<AObject *>(Parseur::getX(), NULL));
  std::random_device generator;
  std::uniform_int_distribution<int> distribution(1, 100);

  for (unsigned int y = 0; y < map.size(); ++y)
    for (unsigned int x = 0; x < map[y].size(); ++x)
      {
	if (!x || !y || y + 1 == map.size() || x + 1 == map[y].size())
	  map[y][x] = new Wall(x, y);
	else
	  {
	    if (distribution(generator) <= Parseur::getDensite() && !dynamic_cast<Wall *>(map[y - 1][x]))
	      map[y][x] = new Wall(x, y);
	    else
	      map[y][x] = new Box(x, y);
	  }
      }
  return (map);
}
