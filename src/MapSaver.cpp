//
// MapSaver.cpp for MapSaver in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Mon Jun  8 16:18:51 2015 Leo Thevenet
// Last update Thu Jun 11 16:06:17 2015 polydo_s
//

#include "MapSaver.hh"

namespace	MapSaver
{
  void		saveMap(std::vector< std::vector<AObject *> > map, std::list<APlayer *> player, int w, int h, int p)
  {
    std::ofstream fichier("./map/user", std::ofstream::out | std::ofstream::trunc);

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
		    if (dynamic_cast<Wall *>(map[i][j]))
		      fichier << 1 << " ";
		    else if (dynamic_cast<Box *>(map[i][j]))
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
      std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
  }

  std::tuple<int, int, int, std::vector< std::vector<AObject *> >, std::list<APlayer *> > getMap(const std::string & fileName)
  {
    std::ifstream fichier(fileName, std::ifstream::in);

    if(!fichier)
      throw std::runtime_error("No saved map");

    int p, w, h;
    float x, y;

    fichier >> w;
    fichier >> h;
    fichier >> p;
    fichier >> x;
    fichier >> y;

    std::list<APlayer *> players;
    PhysicalPlayer *p1 = new PhysicalPlayer(x, y, APlayer::DOWN);
    players.push_back(p1);
    if (p == 2)
      {
	fichier >> x;
	fichier >> y;
	PhysicalPlayer *p2 = new PhysicalPlayer(x, y, APlayer::UP);
	players.push_back(p2);
      }

    // std::get<3>(foo) = players;

    int a;
    std::vector<std::vector<AObject *> > map(w, std::vector<AObject *>(h));
    std::cout << w << "  " << h << "  " << std::endl;
    for (int i = 0; i < w; ++i)
      {
	for (int j = 0; j < h; ++j)
	  {
	    fichier >> a;
	    std::cout << a << " ";
	    if (a == 1)
	      map[i][j] = new Wall(i, j);
	    else if (a == 2)
	      map[i][j] = new Box(i, j);
	    else
	      map[i][j] = NULL;
	  }
	std::cout << std::endl;
      }
    std::tuple<int, int, int, std::vector< std::vector<AObject *> >, std::list<APlayer *> > foo(w, h, p, map, players);

    fichier.close();
    return foo;
  }
};
