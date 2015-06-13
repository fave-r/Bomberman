//
// MapSaver.hh for MapSaver in /home/theven_l/work/Bomberman
//
// Made by Leo Thevenet
// Login   <theven_l@epitech.net>
//
// Started on  Mon Jun  8 16:03:25 2015 Leo Thevenet
// Last update Sat Jun 13 18:23:35 2015 clément jean
//

#ifndef __MAPSAVER_HH__
#define __MAPSAVER_HH__

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Bomberman.hh"

namespace	MapSaver
{
  void		saveMap(std::vector< std::vector<AObject *> >, std::list<APlayer *>, int, int, int);
  const std::tuple<int, int, int, std::vector< std::vector<AObject *> >
		   , std::list<APlayer *> > getMap(const std::string &);
};

bool     saveScreenshot(const std::string &filename, int w, int h);

#endif
