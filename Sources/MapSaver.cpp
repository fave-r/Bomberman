//
// MapSaver.cpp for MapSaver in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Mon Jun  8 16:18:51 2015 Leo Thevenet
// Last update Sun Jun 14 14:04:56 2015 Leo Thevenet
//

#include "MapSaver.hh"

namespace	MapSaver
{
  void		saveMap(std::vector< std::vector<AObject *> > map, std::list<APlayer *> player, int w, int h, int p)
  {
    std::ofstream fichier("./Map/user", std::ofstream::out | std::ofstream::trunc);

    if(fichier)
      {
	fichier << w << std::endl << h << std::endl << p << std::endl;
	std::list<APlayer *>::iterator it;
	for (it = player.begin(); it != player.end(); ++it)
	  {
	    fichier << (*it)->getX() << std::endl;
	    fichier << (*it)->getY() << std::endl;
	  }
	for (size_t i = 0; i < map.size(); ++i)
	  {
	    for (size_t j = 0; j < map[i].size(); ++j)
	      {
		if (map[i][j] != NULL)
		  {
		    if (map[i][j]->getType() == "W")
		      fichier << 1 << " ";
		    else if (map[i][j]->getType() == "B")
		      fichier << 2 << " ";
		    else
		      fichier << 0 << " ";
		  }
		else
		  fichier << 0 << " ";
	      }
	    fichier << std::endl;
	  }
	fichier.close();
      }
    else
      throw loading_error("Can save the map");
  }

  const std::tuple<int, int, int, std::vector< std::vector<AObject *> >
		   , std::list<APlayer *> > getMap(const std::string & fileName)
  {
    std::ifstream fichier(fileName, std::ifstream::in);

    if(!fichier)
      throw loading_error("No saved map");

    int p, w, h;
    float x, y;

    fichier >> h;
    fichier >> w;
    fichier >> p;
    fichier >> x;
    fichier >> y;

    if (w > 100 || h > 100 || w < 10 || h < 10 || p < 1 || p > 2 || x > (h - 2) || x < 1 || y > (w - 2) || y < 1)
      throw loading_error("Map corrupted");
    std::list<APlayer *> players;
    PhysicalPlayer *p1 = new PhysicalPlayer(x, y, APlayer::DOWN);
    players.push_back(p1);
    if (p == 2)
      {
	fichier >> x;
	fichier >> y;
	if (x > (h - 2) || x < 1 || y > (w - 2) || y < 1)
	  throw loading_error("Map corrupted");
	PhysicalPlayer *p2 = new PhysicalPlayer(x, y, APlayer::UP);
	players.push_back(p2);
      }

    int a;
    std::vector<std::vector<AObject *> > map(w, std::vector<AObject *>(h));
    for (int i = 0; i < w; ++i)
      {
	for (int j = 0; j < h; ++j)
	  {
	    fichier >> a;
	    if (a == 1)
	      map[i][j] = new Wall(j, i);
	    else if (a == 2)
	      map[i][j] = new Box(j, i);
	    else if (a == 0)
	      map[i][j] = NULL;
	    else
	      throw loading_error("Map corrupted");
	    if ((j == 0 || j == (h - 1) || i == 0 || i == (w - 1)) && a != 1)
	      throw loading_error("Map corrupted");
	  }
	if (static_cast<int>(map[i].size()) != h)
	  throw loading_error("Map corrupted");
      }
    if (static_cast<int>(map.size()) != w)
      throw loading_error("Map corrupted");

    std::tuple<int, int, int, std::vector< std::vector<AObject *> >, std::list<APlayer *> > foo(w, h, p, map, players);

    fichier.close();
    return foo;
  }
};
